#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <chrono>
#include <thread>
#include <bitset>

#include "socketclient.h"

using namespace std;

int SocketClient::receive_data() {
    while(true) {

        uint8_t received[1028] = {};

        int bytesReceived = recv(clientSocket, received, sizeof(received), 0);
        if(bytesReceived <= 0) {
            cerr << "Could not receive message from server!";
            return 1;
        } else {
            uint8_t messageID = received[0]; // Message ID (1 byte)
            uint8_t vectorMeta = received[1]; // Vector metadata (1 byte)
            uint8_t vectorLength = (vectorMeta >> 4) & 0x0F; // Get the 4 high bits for vector length
            uint8_t vectorDataType = vectorMeta & 0x0F; // Get the 4 low bits for vector data type
        
            cout << "Received message with ID: " << (int)messageID << endl;
            cout << "Vector Length: " << (int)vectorLength << ", Data Type: " << (int)vectorDataType << endl;
        
            // Depending on the vector data type, we process the data
            uint8_t* dataPtr = received + 2; // The data starts after the first two bytes
            if (vectorDataType == 0) { // uint32
                uint32_t data[vectorLength];
                memcpy(data, dataPtr, sizeof(uint32_t) * vectorLength);
        
                for (int i = 0; i < vectorLength; ++i) {
                    cout << "Data " << i << ": " << data[i] << endl;
                }
            } else if (vectorDataType == 1) { // int32
                int32_t data[vectorLength];
                memcpy(data, dataPtr, sizeof(int32_t) * vectorLength);
        
                for (int i = 0; i < vectorLength; ++i) {
                    cout << "Data " << i << ": " << data[i] << endl;
                }
            } else if (vectorDataType == 2) { // float
                float data[vectorLength];
                memcpy(data, dataPtr, sizeof(float) * vectorLength);
        
                for (int i = 0; i < vectorLength; ++i) {
                    cout << "Data " << i << ": " << data[i] << endl;
                }
            } else if (vectorDataType == 3) { // boolean
                bool data[vectorLength];
                memcpy(data, dataPtr, sizeof(bool) * vectorLength);
                for (int i = 0; i < vectorLength; ++i) {
                    cout << "Data " << i << ": " << data[i] << endl;
                }

                switch(messageID) {
                    case 101:
                        if(i2cClient.write_keukenlampen_data(data[0])) {
                            cerr << "Could not write to keukenlampen!" << endl;
                        }
                        break;
                    case 121:
                        if(i2cClient.write_keuken_deuren_data(data[0])) {
                            cerr << "Could not write to keuken deuren!" << endl;
                        }
                        break;
                    case 131:
                        if(i2cClient.write_brandalarm_signal(data[0])) {
                            cerr << "Could not write brandalarm data!" <<endl;
                        }
                        break;
                    case 123:
                        if(i2cClient.write_restaurant_deuren_data(data[0])) {
                            cerr << "Could not write to restaurant deuren!" << endl;
                        }
                        break;
                }
            } else if (vectorDataType == 4) { // ASCII null-terminated string
                char data[1024];
                memcpy(data, dataPtr, 1024);
                cout << "Data " << ": " << data << endl;
            } else if (vectorDataType == 5) { // uint8
                uint8_t data[vectorLength];
                memcpy(data, dataPtr, sizeof(uint8_t) * vectorLength);
                
                cout << "Data : ";
                for (size_t i = 0; i < vectorLength; ++i)
                {
                    cout << bitset<8>(data[i]) << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}

int SocketClient::send_testData() {
    while(1) {
        
        float co2_value = 600.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1100.0 - 600.0)));
        float humidity_value = 30.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (50.0 - 30.0)));
        float temperature_value = 19.5 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (23.0 - 19.5)));

        uint8_t send_buffer[12];
        memcpy(send_buffer, &temperature_value, 4);
        memcpy(send_buffer + 4, &humidity_value, 4);
        memcpy(send_buffer + 8, &co2_value, 4);

        if(send_dataframe(
            122, // messageID 
            3, // vector size 1 
            2,  // float
            send_buffer,
            12 // 4 bytes for a float
        )) {
            cerr << "Could not send CO2 value to server!" << endl;
            return 1;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}

// Take values from the I2C bus and translate them to socket messages
int SocketClient::send_data() {
    while(true) {
        // environment sensor
        if(i2cClient.read_temp_humidity_data(environment_values)) {
            cerr << "Failed to read temperature/humidity data, not sending to server!" << endl;
        } else if (i2cClient.read_co2_data(environment_values)) { 
            cerr << "Failed to read co2 data, not sending to server!" << endl;
        } else {

            uint8_t send_buffer[12];
            memcpy(send_buffer, environment_values, 12);
            if(send_dataframe(
                122, // messageID 
                3, // vector size 3
                2,  // float
                send_buffer,
                12 // 4 bytes for a float, times 3 = 12
            )) {
                cerr << "Could not send environment values to server!" << endl;
            }
        }

        this_thread::sleep_for(chrono::seconds(1));
    }
}

int SocketClient::send_dataframe(
    uint8_t messageID,
    int vector_size, // <= 15
    int datatype,    //  0..4, see docs/dataformaat
    uint8_t *data,
    uint datasize // <= 1022
) {
    uint8_t message[2 + datasize] = {};
    message[0] = messageID;
    message[1] = (vector_size << 4) | datatype;
    memcpy(message + 2, data, datasize);
    if (send(clientSocket, message, datasize + 2, 0) == -1)
    {
        cerr << "Message to server failed!" << endl;
        return -1;
    }
    else
    {
        cout << "Sent data ";
        for (size_t i = 0; i < datasize; ++i)
        {
            cout << bitset<8>(data[i]) << " ";
        }
        cout << " to server! (messageID: " << static_cast<int>(messageID) << ")" << endl;
        return 0;
    }
}

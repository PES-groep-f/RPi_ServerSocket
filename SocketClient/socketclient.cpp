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
#include "globals.h"
#include "I2Cclient.h"

using namespace std;

int receive_data() {
    while(1) {

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
}

int send_testData() {
    while(1) {
        
        // CO2 sensor
        float co2_value = 600.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1100.0 - 600.0)));
        if(send_dataframe(
            111, // messageID 
            1, // vector size 1 
            2,  // float
            reinterpret_cast<uint8_t*>(&co2_value),
            4 // 4 bytes for a float
        )) {
            cerr << "Could not send CO2 value to server!" << endl;
            return 1;
        }
        this_thread::sleep_for(chrono::seconds(1));

        // humidity sensor
        float humidity_value = 30.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (50.0 - 30.0)));
        if(send_dataframe(
            112, // messageID 
            1, // vector size 1 
            2,  // float
            reinterpret_cast<uint8_t*>(&humidity_value),
            4 // 4 bytes for a float
        )) {
            cerr << "Could not send humidity value to server!" << endl;
            return 1;
        }
        this_thread::sleep_for(chrono::seconds(1));

        // temperature sensor
        float temperature_value = 19.5 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (23.0 - 19.5)));
        if(send_dataframe(
            122, // messageID 
            1, // vector size 1 
            2,  // float
            reinterpret_cast<uint8_t*>(&temperature_value),
            4 // 4 bytes for a float
        )) {
            cerr << "Could not send temperature value to server!" << endl;
            return 1;
        }

        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}

// Take values from the I2C bus and translate them to socket messages
// !TODO: implement timeslots if this is necessary, or other chrono polling logic
int send_data() {
    while(1) {
        float co2_value = read_co2_data();
        if(send_dataframe(
            111, // messageID 
            1, // vector size 1 
            2,  // float
            reinterpret_cast<uint8_t*>(&co2_value),
            4 // 4 bytes for a float
        )) {
            cerr << "Could not send CO2 value to server!" << endl;
            return 1;
        }
                // humidity sensor
        float humidity_value = read_humidity_data();
        if(send_dataframe(
            112, // messageID 
            1, // vector size 1 
            2,  // float
            reinterpret_cast<uint8_t*>(&humidity_value),
            4 // 4 bytes for a float
        )) {
            cerr << "Could not send humidity value to server!" << endl;
            return 1;
        }

        // temperature sensor
        float temperature_value = read_temperature_data();
        if(send_dataframe(
            122, // messageID 
            1, // vector size 1 
            2,  // float
            reinterpret_cast<uint8_t*>(&temperature_value),
            4 // 4 bytes for a float
        )) {
            cerr << "Could not send temperature value to server!" << endl;
            return 1;
        }
    }
}

int send_dataframe(
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
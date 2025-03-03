#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>

using namespace std;

// Function to handle communication with a single client
void handleClient(int clientSocket) {
    cout << "Socket " << clientSocket << " opened." << endl;

    uint8_t buffer[1024] = {0};

    while (true) {
        // Receive data from client
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived <= 0) {
            // If no data received or client disconnected
            cout << "Client disconnected or error occurred on socket " << clientSocket << "." << endl;
            break;  // Exit the loop and close the socket
        }

        // Null-terminate the received message
        buffer[bytesReceived] = '\0';

        uint8_t messageID = buffer[0]; // Message ID (1 byte)
        uint8_t vectorMeta = buffer[1]; // Vector metadata (1 byte)
        uint8_t vectorLength = (vectorMeta >> 4) & 0x0F; // Get the 4 high bits for vector length
        uint8_t vectorDataType = vectorMeta & 0x0F; // Get the 4 low bits for vector data type
    
        cout << "Received message with ID: " << (int)messageID << endl;
        cout << "Vector Length: " << (int)vectorLength << ", Data Type: " << (int)vectorDataType << endl;
    
        // Depending on the vector data type, we process the data
        uint8_t* dataPtr = buffer + 2; // The data starts after the first two bytes
        if (vectorDataType == 0) { // uint32
            uint32_t data[vectorLength];
            memcpy(data, dataPtr, sizeof(uint32_t) * vectorLength);
    
            for (int i = 0; i < vectorLength; ++i) {
                cout << "Data " << i << ": " << data[i] << endl;
            }

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
            char data[vectorLength];
            memcpy(data, dataPtr, sizeof(char) * vectorLength);
    
            for (int i = 0; i < vectorLength; ++i) {
                cout << "Data " << i << ": " << data[i] << endl;
            }
        }

        // Respond to the client
        const char* response = "Message received!";
        send(clientSocket, response, strlen(response), 0);
    }

    // Close the client socket after communication
    close(clientSocket);
    cout << "Socket " << clientSocket << " closed." << endl;
}

int setup() {
    // Create server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Socket creation failed!" << endl;
        return 1;
    }
    
    // Setup server address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    // Bind the socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        cerr << "Binding failed!" << endl;
        close(serverSocket);
        return 1;
    }

    return serverSocket;
}

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

    char buffer[1024] = {0};

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
        cout << "Message from client: " << buffer << endl;

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

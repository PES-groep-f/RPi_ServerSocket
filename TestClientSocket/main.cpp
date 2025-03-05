#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <chrono>
#include <thread>

#include "clientsocket.h"

using namespace std;

int main()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);
    
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection failed");
        return 1;
    }


    cout << "Connected to the server. Sending messages..." << endl;

    int i = 123;
    uint8_t message[13]; 
    message[1] = (3 << 4) | 4;
    char data[] = "hello world";
    memcpy(message + 2, data, 11);

    while (true) {
        message[0] = i; // message ID

        // if (send(clientSocket, message, 13, 0) == -1) {
        //     cerr << "Send failed! Error code: " << errno << endl;
        //     this_thread::sleep_for(chrono::seconds(1));
        //     continue;
        // }

        // cout << "Sent message with ID: " << i << endl;

        // Sleep for 1 second
        this_thread::sleep_for(chrono::seconds(1));

        i++;
    }

    close(clientSocket);

    return 0;
}
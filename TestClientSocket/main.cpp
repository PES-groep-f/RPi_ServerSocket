#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    inet_pton(AF_INET, "169.254.10.157", &serverAddress.sin_addr);
    
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection failed");
        return 1;
    }


    cout << "Connected to the server. Sending messages..." << endl;

    int counter = 0; // Counter for messages

    while (true) {
        // Convert the integer to a string and send it
        string message = to_string(counter);
        if (send(clientSocket, message.c_str(), message.length(), 0) == -1) {
            cerr << "Send failed! Error code: " << errno << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }

        cout << "Sent: " << message << endl;
        
        // Increment counter
        counter++;

        // Sleep for 1 second
        this_thread::sleep_for(chrono::seconds(1));
    }

    close(clientSocket);

    return 0;
}
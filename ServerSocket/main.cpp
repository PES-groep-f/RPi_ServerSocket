#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>

#include "socketserver.h"

using namespace std;

int main() {
    int serverSocket = setup();

    if(serverSocket == 1) {
        cerr << "Server socket failed to setup!" << endl;
        return 1;
    }

    // Listen for connections
    if (listen(serverSocket, 5) == -1) {
        cerr << "Listening failed!" << endl;
        close(serverSocket);
        return 1;
    }

    cout << "Server listening on port 8080..." << endl;

    // Accept multiple clients using threads
    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            cerr << "Client connection failed!" << endl;
            continue;
        }

        // Start a new thread to handle the client
        thread clientThread(handleClient, clientSocket);
        clientThread.detach(); // Allow the thread to run independently
    }

    // Close the server socket (unreachable, but good practice)
    close(serverSocket);
    return 0;
}

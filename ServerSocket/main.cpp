#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex> 
#include <QApplication>

#include "main_window.h"
#include "serversocket.h"
#include "globals.h"

using namespace std;

int runQT(int argc, char *argv[]) {
    QApplication app(argc, argv);

    mainWindow = new MainWindow;
    mainWindow->show();

    int res = app.exec();
    delete mainWindow;
    return res;
}

int main(int argc, char *argv[]) {
    thread qtThread(runQT, argc, argv);
    qtThread.detach();

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
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == -1) {
            cerr << "Client connection failed!" << endl;
            continue;
        }
        
        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
        cout << "New connection from: " << clientIP << endl;

        {
            lock_guard<mutex> lock(clientMapMutex);
            clientMap[clientIP] = clientSocket; // Store the IP -> socket mapping
        }
        // Start a new thread to handle the client
        thread clientThread(handleClient, clientSocket, clientIP);
        clientThread.detach(); // Allow the thread to run independently
    }

    // Close the server socket (unreachable, but good practice)
    close(serverSocket);
    return 0;
}

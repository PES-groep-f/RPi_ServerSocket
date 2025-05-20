#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex> 
#include <QApplication>

#include "serversocket.h"
#include "globals.h"

using namespace std;

/**
 * @brief Start de Qt GUI applicatie in een aparte thread.
 * 
 * Initialiseert de QApplication en toont het hoofdvenster.
 * 
 * @param argc Aantal commandoregelargumenten.
 * @param argv Array met commandoregelargumenten.
 * @return int Retourneert de exitcode van de Qt applicatie.
 */
int runQT(int argc, char *argv[]) {
    QApplication app(argc, argv);

    mainWindow = new MainWindow;
    mainWindow->show();

    int res = app.exec();
    delete mainWindow;
    return res;
}

/**
 * @brief De hoofdprogramma functie die de server opstart.
 * 
 * Start de Qt GUI in een aparte thread, initialiseert en opent een TCP server
 * socket op poort 8080, accepteert inkomende clientverbindingen en start voor
 * elke client een aparte thread om communicatie af te handelen.
 * 
 * @param argc Aantal commandoregelargumenten.
 * @param argv Array met commandoregelargumenten.
 * @return int Retourneert 0 bij succes, anders een foutcode.
 */
int main(int argc, char *argv[]) {
    thread qtThread(runQT, argc, argv);
    qtThread.detach();

    ServerSocket ssocket = ServerSocket();
    int file_descriptor = ssocket.setup();

    if(file_descriptor == 1) {
        cerr << "Server socket failed to setup!" << endl;
        return 1;
    }

    // Listen for connections
    if (listen(file_descriptor, 5) == -1) {
        cerr << "Listening failed!" << endl;
        close(file_descriptor);
        return 1;
    }

    cout << "Server listening on port 8080..." << endl;

    // Accept multiple clients using threads
    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSocket = accept(file_descriptor, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == -1) {
            cerr << "Client connection failed!" << endl;
            continue;
        }
        
        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
        cout << "New connection from: " << clientIP << endl;

        {
            lock_guard<mutex> lock(clientMapMutex);
            clientMap[string(clientIP)] = clientSocket; // Store the IP -> socket mapping
        }
        // Start a new thread to handle the client
        thread clientThread(&ServerSocket::handleClient, &ssocket, clientSocket, clientIP);
        clientThread.detach(); // Allow the thread to run independently
    }

    // Close the server socket (unreachable, but good practice)
    close(file_descriptor);
    return 0;
}

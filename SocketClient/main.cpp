#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <chrono>
#include <thread>

#include "globals.h"
#include "socketclient.h"
#include "I2Cclient.h"

using namespace std;

int main()
{
    if(setup_I2C()) {
        return 1;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    inet_pton(AF_INET, "169.254.10.157", &serverAddress.sin_addr);
    
    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Connection with server failed");
        return 1;
    }

    cout << "Connected to the server. Sending messages..." << endl;
    clientSocket = sock;

    thread receiveThread(receive_data);
    thread sendThread(send_data);
    // thread test_sendThread(send_testData);

    receiveThread.join();
    sendThread.join();
    // test_sendThread.join();

    close(clientSocket);
	close(fd0);
	close(fd1);
	close(fd2);
	close(fd3);
    return 0;
}

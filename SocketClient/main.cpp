#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <chrono>
#include <thread>
#include <fcntl.h>

#include "socketclient.h"
#include "I2Cclient.h"

using namespace std;

int main()
{
    // Connect to ServerSocket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    inet_pton(AF_INET, "169.254.10.157", &serverAddress.sin_addr);
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags);

    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        if (errno != EINPROGRESS) {
            perror("connect");
            return 1;
        }
    }

    cout << "Connected to the server. Sending messages..." << endl;

    I2CClient& i2c = I2CClient::getInstance();
    if(i2c.setup_I2C()) {
        return 1;
    }

    SocketClient socketClient(i2c, sock);

    std::thread receiverThread([&]() {
        socketClient.receive_data();
    });

    std::thread senderThread([&]() {
        socketClient.send_data();
    });

    receiverThread.join();
    senderThread.join();
    return 0;
}

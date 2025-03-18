#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <iostream>
#include <cstring>

using namespace std;

int setup();

void handleClient(int clientSocket, char ip_address[]);
int send_dataframe(
    string ip_address, 
    uint8_t messageID,
    int vector_size, // <= 15
    int datatype, //  0..4, zie docs/dataformaat
    uint8_t* data, 
    uint datasize // <= 1022
);
void receive_dataframe(uint8_t buffer[1024]);

#endif
#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <iostream>
#include <cstring>

using namespace std;

enum DataType {
    UINT32 = 0,
    INT32  = 1,
    FLOAT  = 2,
    BOOL   = 3,
    ASCII  = 4,
    UINT8  = 5
};

class ServerSocket {
public:
    /**
     * @brief Initialiseert de serversocket.
     * 
     * Maakt een nieuwe TCP socket aan, bindt deze aan poort 8080, en retourneert de socket descriptor.
     * 
     * @return De socket file descriptor bij succes, of 1 bij fout.
     */
    int setup();

    /**
     * @brief Behandelt communicatie met een verbonden client.
     * 
     * Leest inkomende data van de client socket en verwerkt het met `receive_dataframe`.
     * Bij verbreking van de verbinding wordt de socket gesloten.
     * 
     * @param clientSocket De socket file descriptor van de client.
     * @param ip_address Het IP-adres van de client (gebruikt voor verwijderen uit `clientMap`).
     */
    void handleClient(int clientSocket, char ip_address[]);

    /**
     * @brief Verstuurt een dataframe naar een specifieke client.
     * 
     * Bouwt een bericht op volgens het gedefinieerde dataformaat en verstuurt dit via de juiste client socket.
     * 
     * @param ip_address Het IP-adres van de client.
     * @param messageID Een identificatiecode voor het bericht (eerste byte).
     * @param vector_size Aantal elementen in de datavector (maximaal 15).
     * @param datatype Het datatype van de vector (0 = uint32_t, 1 = int32_t, 2 = float, 3 = bool, 4 = string).
     * @param data Pointer naar de databuffer.
     * @param datasize Grootte van de databuffer (maximaal 1022 bytes).
     * 
     * @return 0 bij succes, -1 bij fout (bv. IP niet gevonden of verzenden mislukt).
     */
    int send_dataframe(
        string ip_address, 
        uint8_t messageID,
        int vector_size, 
        int datatype, 
        uint8_t* data, 
        uint datasize
    );

    /**
     * @brief Verwerkt een ontvangen dataframe.
     * 
     * Decodeert het dataframe volgens het dataformaat en roept afhankelijk van het messageID 
     * de juiste functies aan in de GUI.
     * 
     * @param buffer Een buffer van exact 1024 bytes die het volledige ontvangen bericht bevat.
     */
    void receive_dataframe(uint8_t buffer[1024]);

};

#endif // SERVERSOCKET_H

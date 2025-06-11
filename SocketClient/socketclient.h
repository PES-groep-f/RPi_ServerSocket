#include "I2Cclient.h"

class SocketClient {
private:
    float environment_values[3];
    I2CClient& i2cClient;
    int clientSocket;

public:
    SocketClient(I2CClient& i2cClient, int sock): 
    i2cClient(i2cClient), clientSocket(sock) {}
    ~SocketClient() {
        close(clientSocket);
    };
    
    int receive_data();
    int send_testData();
    int send_data(); 

    // stuurt neppe berichten met generereerde waardes 
    void test_co2Sensor(); // stuurt waardes tussen 600.0 en 1100.0
    void test_temperatureSensor(); // stuurt waardes tussen 19.5 en 23.0
    void test_humiditySensor(); // stuurt waardes tussen 30.0 en 50.0
    int send_dataframe(
        uint8_t messageID,
        int vector_size, // <= 15
        int datatype,    //  0..4, see docs/dataformaat
        uint8_t *data,
        uint datasize // <= 1022
    );
};

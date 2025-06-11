#ifndef I2CCLIENT_H
#define I2CCLIENT_H

#include <mutex>

class I2CClient {
enum CommandCode : uint8_t { // command codes voor STM 4, zie dataflow diagram
    KEUKENLAMPEN_ON = 1,
    KEUKENLAMPEN_OFF = 0,
    KEUKEN_DEUREN_OPEN = 3,
    KEUKEN_DEUREN_CLOSE = 2,
    RESTAURANT_DEUREN_OPEN = 5,
    RESTAURANT_DEUREN_CLOSE = 4,
};

private:
    // Singleton instance control
    I2CClient();
    ~I2CClient();
    I2CClient(const I2CClient&) = delete;
    I2CClient& operator=(const I2CClient&) = delete;

    int clientSocket;
    const int STMboard0_adress = 0x14;
    const int STMboard1_adress = 0x15;
    const int STMboard2_adress = 0x16;
    const int STMboard3_adress = 0x17;

    int fd0 = -1;
    int fd1 = -1;
    int fd2 = -1;
    int fd3 = -1;

    mutable std::mutex mtx;
public:
    static I2CClient& getInstance() {
        static I2CClient instance;
        return instance;
    }

    int setup_I2C();
    int read_temp_humidity_data(float* out);
    int read_co2_data(float* out);
    int write_keukenlampen_data(bool aan);
    int write_keuken_deuren_data(bool aan);
    int write_restaurant_deuren_data(bool aan);
    int write_brandalarm_signal(bool aan);
};

#endif
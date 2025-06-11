#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <bitset>

#include "I2Cclient.h"

using namespace std;

float bytesToFloat(uint8_t* bytes) {
    float v;
    memcpy(&v, bytes, sizeof(float));
    return v;
}

short bytesToShort(uint8_t* bytes) {
    short v;
    memcpy(&v, bytes, sizeof(short));
    return v;
}

I2CClient::I2CClient() {
}

I2CClient::~I2CClient() {
    if (fd0 >= 0) close(fd0);
    if (fd1 >= 0) close(fd1);
    if (fd2 >= 0) close(fd2);
    if (fd3 >= 0) close(fd3);
}

int I2CClient::setup_I2C() {
    std::lock_guard<std::mutex> lock(mtx);

    const char* device = "/dev/i2c-1";
    if ((fd0 = open(device, O_RDWR)) < 0) {
        cerr << "Failed to open I2C bus!" << endl;
        return 1;
    }

    fd1 = dup(fd0);
    fd2 = dup(fd0);
    fd3 = dup(fd0);
    if (fd1 < 0 || fd2 < 0 || fd3 < 0 ) {
        cerr << "Failed to duplicate file descriptors!" << endl;
        return 1;
    }

    cout << "I2C Communication established with STM boards!" << endl;
    return 0;
}

int I2CClient::read_temp_humidity_data(float* out) {
    std::lock_guard<std::mutex> lock(mtx);

    if (ioctl(fd0, I2C_SLAVE, STMboard0_adress) < 0) {
        cerr << "Failed to select STMboard0!" << endl;
        return 1;
    }

    uint8_t buffer[8] = {};
    if (read(fd0, buffer, 8) != 8) {
        cerr << "Could not read temp/humidity data!" << endl;
        return 1;
    }

    out[0] = bytesToFloat(buffer);
    out[1] = bytesToFloat(buffer + 4);
    return 0;
}

int I2CClient::read_co2_data(float* out) {
    std::lock_guard<std::mutex> lock(mtx);

    if (ioctl(fd1, I2C_SLAVE, STMboard1_adress) < 0) {
        cerr << "Failed to select STMboard1!" << endl;
        return 1;
    }

    uint8_t buffer[2] = {};
    if (read(fd1, buffer, 2) != 2) {
        cerr << "Could not read CO2 data!" << endl;
        return 1;
    }

    out[2] = (float) bytesToShort(buffer);
    return 0;
}

int I2CClient::write_keukenlampen_data(bool aan) {
    std::lock_guard<std::mutex> lock(mtx);

    if (ioctl(fd2, I2C_SLAVE, STMboard2_adress) < 0) {
        cerr << "Failed to select STMboard2!" << endl;
        return 1;
    }

    uint8_t v = aan ? CommandCode::KEUKENLAMPEN_ON : CommandCode::KEUKENLAMPEN_OFF;
    if (write(fd2, &v, 1) != 1) {
        cerr << "Could not send keukenlampen data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int I2CClient::write_keuken_deuren_data(bool aan) {
    std::lock_guard<std::mutex> lock(mtx);

    if (ioctl(fd2, I2C_SLAVE, STMboard2_adress) < 0) {
        cerr << "Failed to select STMboard2!" << endl;
        return 1;
    }

    uint8_t v = aan ? CommandCode::KEUKEN_DEUREN_OPEN : CommandCode::KEUKEN_DEUREN_CLOSE;
    if (write(fd2, &v, 1) != 1) {
        cerr << "Could not send keuken deuren data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int I2CClient::write_restaurant_deuren_data(bool aan) {
    std::lock_guard<std::mutex> lock(mtx);

    if (ioctl(fd2, I2C_SLAVE, STMboard2_adress) < 0) {
        cerr << "Failed to select STMboard2!" << endl;
        return 1;
    }

    uint8_t v = aan ? CommandCode::RESTAURANT_DEUREN_OPEN : CommandCode::RESTAURANT_DEUREN_CLOSE;
    if (write(fd2, &v, 1) != 1) {
        cerr << "Could not send restaurant deuren data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int I2CClient::write_brandalarm_signal(bool aan) {
    std::lock_guard<std::mutex> lock(mtx);

    if (ioctl(fd3, I2C_SLAVE, STMboard3_adress) < 0) {
        cerr << "Failed to select STMboard3!" << endl;
        return 1;
    }
    uint8_t v = aan ? 1 : 0;
    if (write(fd3, &v, 1) != 1) {
        cerr << "Could not send brandalarm data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 4" << endl;
    return 0;
}


#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <bitset>
#include "globals.h"

using namespace std;

//int fd0, fd1, fd2; // These should be declared in globals.h or here as needed

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

int setup_I2C() {
    const char* device = "/dev/i2c-1"; // Replace with your actual I2C bus
    if ((fd0 = open(device, O_RDWR)) < 0) {
        cerr << "Failed to open I2C bus!" << endl;
        return 1;
    }

    // Duplicate fd0 for other devices
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

int read_temp_humidity_data(float* out) {
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

int read_co2_data(float* out) {
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

int write_keukenlampen_data(bool aan) {
    if (ioctl(fd2, I2C_SLAVE, STMboard2_adress) < 0) {
        cerr << "Failed to select STMboard2!" << endl;
        return 1;
    }

    uint8_t v = aan ? 1 : 0;
    if (write(fd2, &v, 1) != 1) {
        cerr << "Could not send keukenlampen data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int write_keuken_deuren_data(bool aan) {
    if (ioctl(fd2, I2C_SLAVE, STMboard2_adress) < 0) {
        cerr << "Failed to select STMboard2!" << endl;
        return 1;
    }

    uint8_t v = aan ? 3 : 2;
    if (write(fd2, &v, 1) != 1) {
        cerr << "Could not send keuken deuren data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int write_restaurant_deuren_data(bool aan) {
    if (ioctl(fd2, I2C_SLAVE, STMboard2_adress) < 0) {
        cerr << "Failed to select STMboard2!" << endl;
        return 1;
    }

    uint8_t v = aan ? 5 : 4;
    if (write(fd2, &v, 1) != 1) {
        cerr << "Could not send restaurant deuren data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int write_brandalarm_signal(bool aan) {
    if (ioctl(fd3, I2C_SLAVE, STMboard3_adress) < 0) {
        cerr << "Failed to select STMboard3!" << endl;
        return 1;
    }
	sleep(1);
    uint8_t v = aan ? 1 : 0;
    if (write(fd3, &v, 1) != 1) {
        cerr << "Could not send brandalarm data!" << endl;
        return 1;
    }

    cout << "Sent data: " << bitset<8>(v) << " to STM 4" << endl;
    return 0;
}


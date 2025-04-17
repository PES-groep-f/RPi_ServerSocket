#include <stdio.h>
#include <iostream>
#include <wiringPiI2C.h>
#include <cstring>
#include "globals.h"

using namespace std;

float bytesToFloat(uint8_t* bytes) {
    float v;
    memcpy(&v, bytes, sizeof(float));
    return v;
}

int setup_I2C() {
    fd0 = wiringPiI2CSetup(STMboard0_adress);
    // fd1 = wiringPiI2CSetup(STMboard1_adress);
    // fd2 = wiringPiI2CSetup(STMboard2_adress);
    if (fd0 == -1) {
        cerr << "Failed to initialize I2C!" << endl;
        return 1;
    }

    cout << "I2C Communication Established with STM boards: [" << fd0 << "]!" << endl;
    return 0;
}

float read_co2_data() {
    // return wiringPiI2CReadReg16(fd1, 0xFA); // up to change, depending on the actual register
    return 0.0;
}

float read_temperature_data() {
    uint8_t buffer[4];
    int readBytes = wiringPiI2CRawRead(fd0, buffer, 4);
    if(readBytes != 4) {
        cerr << "Could not read temperature data!" << endl;
        return -1.0;
    }
    return bytesToFloat(buffer);
}

float read_humidity_data() {
    return 0.0;
}
#include <stdio.h>
#include <iostream>
#include <wiringPiI2C.h>
#include <cstring>
#include "globals.h"
#include <bitset>

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

int setup_I2C() {
    fd0 = wiringPiI2CSetup(STMboard0_adress);
    fd1 = wiringPiI2CSetup(STMboard1_adress);
    fd2 = wiringPiI2CSetup(STMboard2_adress);
    if (fd0 == -1) {
        cerr << "Failed to initialize I2C!" << endl;
        return 1;
    }

    cout << "I2C Communication established with STM boards!" << endl;
    return 0;
}


int read_temp_humidity_data(float* out) {
    uint8_t buffer[8] = {};
    int readBytes = wiringPiI2CRawRead(fd0, buffer, 8);
    if(readBytes != 8) {
        cerr << "Could not read temp/humidity data! (" << readBytes << " bytes read)" << endl;
        return 1;
    }

    out[0] = bytesToFloat(buffer);
    out[1] = bytesToFloat(buffer + 4);
    return 0;
}

int read_co2_data(float* out) {
    uint8_t buffer[2] = {};
    int readBytes = wiringPiI2CRawRead(fd1, buffer, 2);
    if(readBytes != 2) {
        cerr << "Could not read co2 data! (" << readBytes << " bytes read)" << endl;
        return 1;
    }

    out[2] = (float) bytesToShort(buffer);
    return 0;
}

int write_keukenlampen_data(bool aan) { // aan is true als de keukenlampen aan moeten, anders false
    const uint8_t v = aan? 1 : 0;
    if(wiringPiI2CWrite(fd2, v)) {
        cerr << "Could not send keukenlampen data!" << endl;
        return 1;
    }
    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int write_keuken_deuren_data(bool aan) {
    const uint8_t v = aan? 3 : 2;
    if(wiringPiI2CWrite(fd2, v)) {
        cerr << "Could not send keuken deuren data!" << endl;
        return 1;
    }
    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}

int write_restaurant_deuren_data(bool aan) {
    const uint8_t v = aan? 5 : 4;
    if(wiringPiI2CWrite(fd2, v)) {
        cerr << "Could not send restaurant deuren data!" << endl;
        return 1;
    }
    cout << "Sent data: " << bitset<8>(v) << " to STM 3" << endl;
    return 0;
}
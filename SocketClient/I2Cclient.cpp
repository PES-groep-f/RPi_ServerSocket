#include <iostream>
#include <stdio.h>
#include <wiringPiI2C.h>

#include "globals.h"

using namespace std;

int setup_I2C() {
    fd0 = wiringPiI2CSetup(STMboard0_adress);
    fd1 = wiringPiI2CSetup(STMboard1_adress);
    fd2 = wiringPiI2CSetup(STMboard2_adress);
    if (fd0 == -1 || fd1 == -1 || fd2 == -1) {
        cerr << "Failed to initialize I2C!" << endl;
        return 1;
    }

    cout << "I2C Communication Established with STM boards!" << endl;
    return 0;
}

float read_co2_data() {
    return wiringPiI2CReadReg16(fd1, 0xFA); // up to change, depending on the actual register
}

float read_temperature_data() {
    return wiringPiI2CReadReg16(fd2, 0xFA); // up to change, depending on the actual register
}

float read_humidity_data() {
    return wiringPiI2CReadReg16(fd1, 0xFA); // up to change, depending on the actual register
}
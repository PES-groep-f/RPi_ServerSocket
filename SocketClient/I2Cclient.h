#ifndef I2CCLIENT_H
#define I2CCLIENT_H

int setup_I2C();
float read_co2_data();
float read_temperature_data();
float read_humidity_data();

#endif
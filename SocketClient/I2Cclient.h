#ifndef I2CCLIENT_H
#define I2CCLIENT_H

int setup_I2C();
int read_temp_humidity_data(float* out);
int read_co2_data(float* out);

#endif
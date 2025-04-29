#ifndef I2CCLIENT_H
#define I2CCLIENT_H

int setup_I2C();
int read_temp_humidity_data(float* out);
int read_co2_data(float* out);
int write_keukenlampen_data(bool aan);
int write_keuken_deuren_data(bool aan);
int write_restaurant_deuren_data(bool aan);

#endif
#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

int receive_data();
int send_data();

// sturen neppe berichten met generereerde waardes 
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

#endif
#ifndef I2CCLIENT_H
#define I2CCLIENT_H

/**
 * @file i2cclient.h
 * @brief Bevat functies voor communicatie via I2C met STM32-borden.
 */

/**
 * @brief Initialiseert de I2C-communicatie met drie STM32-borden.
 * 
 * Deze functie probeert verbinding te maken met drie vooraf gedefinieerde
 * I2C-adressen (STMboard0_adress, STMboard1_adress, STMboard2_adress).
 * 
 * @return 0 bij succes, 1 bij fout.
 */
int setup_I2C();

/**
 * @brief Leest temperatuur- en vochtigheidsgegevens via I2C.
 * 
 * De eerste twee elementen van het meegegeven float-array worden overschreven:
 * - `out[0]`: temperatuurwaarde
 * - `out[1]`: vochtigheidswaarde
 * 
 * @param[out] out Array van minimaal 2 floats waarin de meetwaarden worden opgeslagen.
 * @return 0 bij succes, 1 als het lezen mislukt.
 */
int read_temp_humidity_data(float* out);

/**
 * @brief Leest CO2-gegevens via I2C.
 * 
 * De derde positie van het float-array (`out[2]`) wordt overschreven met de CO2-waarde.
 * 
 * @param[out] out Array van minimaal 3 floats waarin de CO2-waarde in `out[2]` wordt geplaatst.
 * @return 0 bij succes, 1 als het lezen mislukt.
 */
int read_co2_data(float* out);

/**
 * @brief Stuurt een signaal om de keukenlampen aan of uit te schakelen.
 * 
 * @param aan true om de lampen aan te zetten, false om ze uit te zetten.
 * @return 0 bij succes, 1 bij fout.
 */
int write_keukenlampen_data(bool aan);

/**
 * @brief Stuurt een commando om de keukendeuren te openen of te sluiten.
 * 
 * @param aan true om te openen, false om te sluiten.
 * @return 0 bij succes, 1 bij fout.
 */
int write_keuken_deuren_data(bool aan);

/**
 * @brief Stuurt een commando om de restaurantdeuren te openen of te sluiten.
 * 
 * @param aan true om te openen, false om te sluiten.
 * @return 0 bij succes, 1 bij fout.
 */
int write_restaurant_deuren_data(bool aan);

#endif // I2CCLIENT_H

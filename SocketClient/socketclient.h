/**
 * @class SocketClient
 * @brief Verzorgt de communicatie tussen de client en server via TCP-sockets.
 *
 * Deze klasse stuurt en ontvangt gestructureerde berichten, waaronder sensorwaarden
 * en besturingscommando's. Ondersteunt zowel echte als gesimuleerde data.
 */
class SocketClient {
private:
    /**
     * @brief Opslag voor omgevingswaarden: temperatuur, vochtigheid, CO₂.
     *
     * - `environment_values[0]` = temperatuur
     * - `environment_values[1]` = luchtvochtigheid
     * - `environment_values[2]` = CO₂
     */
    float environment_values[3];

public:

    /**
     * @brief Ontvangt en verwerkt inkomende berichten van de server.
     * 
     * Ondersteunt diverse datatypes zoals floats, bools, strings, enz.
     * Bepaalt op basis van `messageID` welk subsysteem aangestuurd moet worden.
     *
     * @return 0 bij succes, 1 bij fout.
     */
    int receive_data();

    /**
     * @brief Stuurt gesimuleerde sensorwaarden (CO₂, temperatuur, vochtigheid) naar de server.
     * 
     * De waarden worden willekeurig gegenereerd binnen een realistisch bereik.
     *
     * @return 0 bij succes, 1 bij fout.
     */
    int send_testData();

    /**
     * @brief Leest echte sensorwaarden via I2C en stuurt ze naar de server.
     * 
     * Leest temperatuur, luchtvochtigheid en CO₂, en stuurt dit als `float` vector.
     * 
     * @return 0 bij succes, 1 bij fout.
     */
    int send_data();

    /**
     * @brief Simuleert een CO₂-sensor door willekeurige waarden te genereren en te versturen.
     * 
     * Waarden liggen tussen 600.0 en 1100.0 ppm.
     */
    void test_co2Sensor();

    /**
     * @brief Simuleert een temperatuursensor door waarden tussen 19.5°C en 23.0°C te sturen.
     */
    void test_temperatureSensor();

    /**
     * @brief Simuleert een luchtvochtigheidssensor door waarden tussen 30% en 50% te sturen.
     */
    void test_humiditySensor();

    /**
     * @brief Stuurt een gegevensframe naar de server via de socket.
     *
     * Het frame bestaat uit een message ID, metadata (vectorgrootte en datatype) en de daadwerkelijke data.
     * 
     * @param messageID Unieke identificatie voor het type bericht (bijv. 122 voor sensorwaarden).
     * @param vector_size Aantal elementen in de vector (maximaal 15).
     * @param datatype Type van de data (0: uint32, 1: int32, 2: float, 3: bool, 4: string, 5: uint8).
     * @param data Pointer naar de ruwe data die verstuurd moet worden.
     * @param datasize Grootte van de data in bytes (maximaal 1022).
     * @return 0 bij succes, -1 als het verzenden mislukt.
     */
    int send_dataframe(
        uint8_t messageID,
        int vector_size,
        int datatype,
        uint8_t *data,
        uint datasize
    );
};

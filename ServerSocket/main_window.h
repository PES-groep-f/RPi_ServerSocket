#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "bedieningspaneel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief De hoofdvensterklasse voor de GUI-toepassing.
 * 
 * Deze klasse beheert de interactie met de gebruikersinterface en stuurt 
 * de bijbehorende hardwarecomponenten aan via netwerkcommunicatie.
 * Voor een overzicht van alle messageIDs, zie het dataflow diagram in /docs.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT 

public:
    /**
     * @brief Constructor. Initialiseert het hoofdvenster en koppelt de UI-elementen.
     * @param parent Optionele ouderwidget.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor.
     */
    ~MainWindow();

public slots:
    /**
     * @brief Werk de UI bij met temperatuur-, luchtvochtigheids- en CO2-waarden.
     * @param temperature De gemeten temperatuur.
     * @param humidity De gemeten luchtvochtigheid.
     * @param co2 De gemeten CO2-concentratie.
     */
    void updateEnvironmentValues(float temperature, float humidity, float co2);

    /**
     * @brief Activeer knop voor tafel 1.
     * @param value True als de knop moet worden geactiveerd.
     */
    void updateDrukknop1(bool value);

    /**
     * @brief Activeer knop voor tafel 2.
     * @param value True als de knop moet worden geactiveerd.
     */
    void updateDrukknop2(bool value);

    /**
     * @brief Activeer knop voor tafel 3.
     * @param value True als de knop moet worden geactiveerd.
     */
    void updateDrukknop3(bool value);

    /**
     * @brief Zet de status van de ventilatorknop.
     * @param value True om in te schakelen, false om uit te schakelen.
     */
    void updateVentilator(bool value);

    /**
     * @brief Zet de status van de keukendeurenknop.
     * @param value True om te openen, false om te sluiten.
     */
    void updateKeukenDeurenKnop(bool value);

    /**
     * @brief Zet de status van de restaurantdeurenknop.
     * @param value True om te openen, false om te sluiten.
     */
    void updateRestaurantDeurenKnop(bool value);

    /**
     * @brief Zet de status van de brandalarmknop.
     * @param value True om aan te zetten, false om uit te zetten.
     */
    void updateBrandAlarmKnop(bool value);

private slots:
    /// Behandelt klik op de knop voor keukenlampen.
    void button_lampen_keuken_clicked();

    /// Behandelt klik op de ventilatorknop.
    void button_ventilator_clicked();

    /// Behandelt klik op de knop voor keukendeuren.
    void button_deuren_keuken_clicked();

    /// Behandelt klik op de knop voor restaurantdeuren.
    void button_deuren_restaurant_clicked();

    /// Behandelt loslaten van RGB-sliders voor lamp 1.
    void slider_lampen_rgb_1_released();

    // Zet het brandalarm uit.
    void brandalarm_powerChanged();

    /// Behandelt toepassing van tekstinvoer voor de lichtkrant.
    void lichtkrant_apply_clicked();

    /// Behandelt reset van de lichtkrantinvoer.
    void lichtkrant_reset_clicked();

    // Behandelt de reset van de drukknoppen status LEDs.
    void statusled_0_clicked();
    void statusled_1_clicked();
    void statusled_2_clicked();

private:
    Ui::MainWindow ui; ///< UI-elementen gegenereerd door Qt Designer.
    bool grenswaardeCO2Overschreden = false; ///< Status CO2-drempeloverschrijding.
    bool grenswaardeHumidityOverschreden = false; ///< Status luchtvochtigheidsdrempel.
    bool grenswaardeTemperatureOverschreden = false; ///< Status temperatuurdrempel.
    bool drukknop0_ingedrukt = false; ///< Status drukknop 0.
    bool drukknop1_ingedrukt = false; ///< Status drukknop 1.
    bool drukknop2_ingedrukt = false; ///< Status drukknop 2.
};

#endif // MAIN_WINDOW_H

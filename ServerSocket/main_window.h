#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "bedieningspaneel.h" 

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT 

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateEnvironmentValues(float temperature, float humidity, float co2);
    void updateDrukknop1(bool value);
    void updateDrukknop2(bool value);
    void updateDrukknop3(bool value);
    void updateVentilator(bool value);

private slots:
    void button_lampen_keuken_clicked();
    void button_ventilator_clicked();
    void slider_lampen_rgb_1_released();
    void slider_lampen_rgb_2_released();
    void lichtkrant_apply_clicked();
    void lichtkrant_reset_clicked();

private:
    Ui::MainWindow ui;
    bool grenswaardeCO2Overschreden;
    bool grenswaardeHumidityOverschreden;
    bool grenswaardeTemperatureOverschreden;
    bool drukknop0_ingedrukt = false;
    bool drukknop1_ingedrukt = false;
    bool drukknop2_ingedrukt = false;
};

#endif // MAIN_WINDOW_H

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
    void updateCO2Value(float value);
    void updateHumidityValue(float value);
    void updateTemperatureValue(float value);

private slots:
    void button_lampen_keuken_clicked();

private:
    Ui::MainWindow ui;

};

#endif // MAIN_WINDOW_H

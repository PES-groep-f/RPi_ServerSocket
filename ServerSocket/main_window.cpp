#include "main_window.h"
#include <iostream>
#include "serversocket.h"
#include "globals.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this); 
    
    // connect functions to buttons
    QPushButton* keukenLampenKnop = findChild<QPushButton*>("keukenLampenKnop");
    if (keukenLampenKnop) {
        connect(keukenLampenKnop, &QPushButton::clicked, this, &MainWindow::button_lampen_keuken_clicked);
    }
}

MainWindow::~MainWindow() {}

void MainWindow::button_lampen_keuken_clicked() {
    uint8_t data = 1; // true
    send_dataframe(
        raspberryClientIP,
        101, // message ID for the lamps
        1, // only one value
        3, // boolean
        &data,
        1 // data size 
    );
}

void MainWindow::updateCO2Value(float value) {
    if (ui.co2ValueIndicator) {
        ui.co2ValueIndicator->display(value);
    }
}

void MainWindow::updateTemperatureValue(float value) {
    if (ui.tempValueIndicator) {
        ui.tempValueIndicator->display(value);
    }
}

void MainWindow::updateHumidityValue(float value) {
    if (ui.luchtValueIndicator) {
        ui.luchtValueIndicator->display(value);
    }
}
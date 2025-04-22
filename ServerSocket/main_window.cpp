#include "main_window.h"
#include <iostream>
#include "serversocket.h"
#include "globals.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this); 
    
    // connect functions to buttons
    QPushButton* keukenLampenKnop = findChild<QPushButton*>("keukenLampenKnop");
    if (keukenLampenKnop) connect(keukenLampenKnop, &QPushButton::clicked, this, &MainWindow::button_lampen_keuken_clicked);
    QPushButton* ventilatorKnop = findChild<QPushButton*>("ventilatorKnop");
    if (ventilatorKnop) connect(ventilatorKnop, &QPushButton::toggled, this, &MainWindow::button_ventilator_clicked);

    // connect RGB sliders to functions
    QSlider* rSlider1 = findChild<QSlider*>("lamp1RED");
    QSlider* gSlider1 = findChild<QSlider*>("lamp1GREEN");
    QSlider* bSlider1 = findChild<QSlider*>("lamp1BLUE");
    if (rSlider1 && gSlider1 && bSlider1) {
        connect(rSlider1, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_1_released);
        connect(gSlider1, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_1_released);
        connect(bSlider1, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_1_released);
    }
    QSlider* rSlider2 = findChild<QSlider*>("lamp2RED");
    QSlider* gSlider2 = findChild<QSlider*>("lamp2GREEN");
    QSlider* bSlider2 = findChild<QSlider*>("lamp2BLUE");
    if (rSlider1 && gSlider1 && bSlider1) {
        connect(rSlider2, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_2_released);
        connect(gSlider2, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_2_released);
        connect(bSlider2, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_2_released);
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

void MainWindow::button_ventilator_clicked() {
    if(!ui.ventilatorKnop) {
        fprintf(stderr, "No ventilator button found!");
        return;
    }
    bool checked = ui.ventilatorKnop->isChecked();
    uint8_t data = checked;
    send_dataframe(
        ventilatorIP,
        113, // message ID for the ventilator
        1, // only one value
        3, // boolean
        &data,
        1 // data size 
    );
}

void MainWindow::slider_lampen_rgb_1_released() {
    // send the values of redValueSlider1, greenValueSlider1, and blueValueSlider1 
    uint8_t data[3];
    data[0] = static_cast<uint8_t>(ui.lamp1RED->value()); //red
    data[1] = static_cast<uint8_t>(ui.lamp1GREEN->value()); //green
    data[2] = static_cast<uint8_t>(ui.lamp1BLUE->value()); //blue
    send_dataframe(
        RGBLamp0IP,
        102, // message ID for rgb lamp 1
        3, // three values
        5, // uint8
        data,
        3 // data size 
    );
}

void MainWindow::slider_lampen_rgb_2_released() {
    uint8_t data[3];
    data[0] = static_cast<uint8_t>(ui.lamp2RED->value()); //red
    data[1] = static_cast<uint8_t>(ui.lamp2GREEN->value()); //green
    data[2] = static_cast<uint8_t>(ui.lamp2BLUE->value()); //blue
    send_dataframe(
        RGBLamp1IP,
        103, // message ID for rgb lamp 2
        3, // three values 
        5, // uint8
        data,
        3 // data size 
    );
}

void MainWindow::updateEnvironmentValues(float temperature, float humidity, float co2) {
    if (ui.co2ValueIndicator) {
        ui.co2ValueIndicator->display(co2);

        if (grenswaardeCO2Overschreden && (co2 <= 900)) { // reset
            QPalette palette = ui.co2ValueIndicator->palette();
            palette.setColor(palette.WindowText, Qt::black);            
            ui.co2ValueIndicator->setPalette(palette);
            updateVentilator(false);
        }
        grenswaardeCO2Overschreden = (co2 > 900);
        if (grenswaardeCO2Overschreden) {
            QPalette palette = ui.co2ValueIndicator->palette();
            palette.setColor(palette.WindowText, Qt::red);
            ui.co2ValueIndicator->setPalette(palette);
            updateVentilator(true);
        }
    }

    if (ui.tempValueIndicator) {
        ui.tempValueIndicator->display(temperature);

        if (grenswaardeTemperatureOverschreden && temperature <= 40) { // reset
            QPalette palette = ui.tempValueIndicator->palette();
            palette.setColor(palette.WindowText, Qt::black); 
            ui.co2ValueIndicator->setPalette(palette);
            updateVentilator(false);
        }
        grenswaardeTemperatureOverschreden = (temperature > 40);
        if (grenswaardeTemperatureOverschreden) {
            QPalette palette = ui.tempValueIndicator->palette();
            palette.setColor(palette.WindowText, Qt::red);
            ui.co2ValueIndicator->setPalette(palette);
            updateVentilator(true);
        }
    }

    if (ui.luchtValueIndicator) {
        ui.luchtValueIndicator->display(humidity);
    }
}


void MainWindow::updateDrukknop1(bool value) {
    if (ui.testKnopTafel1 && value) {
        drukknop0_ingedrukt = !drukknop0_ingedrukt;
        ui.testKnopTafel1->setPower(drukknop0_ingedrukt);
    }
}

void MainWindow::updateDrukknop2(bool value) {
    if (ui.testKnopTafel2 && value) {
        drukknop1_ingedrukt = !drukknop1_ingedrukt;
        ui.testKnopTafel2->setPower(drukknop1_ingedrukt);
    }
}

void MainWindow::updateDrukknop3(bool value) {
    if (ui.testKnopTafel3 && value) {
        drukknop2_ingedrukt = !drukknop2_ingedrukt;
        ui.testKnopTafel3->setPower(drukknop2_ingedrukt);
    }
}

void MainWindow::updateVentilator(bool value) {
    if (ui.ventilatorKnop) ui.ventilatorKnop->setChecked(value);
}

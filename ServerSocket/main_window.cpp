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
    QPushButton* keukenDeurenKnop = findChild<QPushButton*>("keukenDeurenKnop");
    if (keukenDeurenKnop) connect(keukenDeurenKnop, &QPushButton::toggled, this, &MainWindow::button_deuren_keuken_clicked);
    QPushButton* restaurantDeurenKnop = findChild<QPushButton*>("restaurantDeurenKnop");
    if (restaurantDeurenKnop) connect(restaurantDeurenKnop, &QPushButton::toggled, this, &MainWindow::button_deuren_restaurant_clicked);

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
    if (rSlider2 && gSlider2 && bSlider2) {
        connect(rSlider2, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_2_released);
        connect(gSlider2, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_2_released);
        connect(bSlider2, &QSlider::sliderReleased, this, &MainWindow::slider_lampen_rgb_2_released);
    }

    // Lichtkrant dialog box 
    QDialogButtonBox* lichtkrant_knoppen = findChild<QDialogButtonBox*>("lichtkrantKnoppen");
    if(lichtkrant_knoppen) {
        QPushButton* applyButton = lichtkrant_knoppen->button(QDialogButtonBox::Apply);
        connect(applyButton, &QPushButton::clicked, this, &MainWindow::lichtkrant_apply_clicked);
        QPushButton* resetButton = lichtkrant_knoppen->button(QDialogButtonBox::Reset);
        connect(resetButton, &QPushButton::clicked, this, &MainWindow::lichtkrant_reset_clicked);
    }
}


MainWindow::~MainWindow() {}

void MainWindow::button_lampen_keuken_clicked() {
    if(!ui.keukenLampenKnop) {
        fprintf(stderr, "No keukenlampen button found!");
        return;
    }
    bool checked = ui.keukenLampenKnop->isChecked();
    uint8_t data = checked; 
    send_dataframe(
        raspberryClientIP,
        101, // message ID for the lamps
        1, // only one value
        3, // boolean
        &data,
        1 // data size 
    );
}

void MainWindow::button_deuren_keuken_clicked() {
    bool checked = ui.keukenDeurenKnop->isChecked();
    uint8_t data = checked; 
    send_dataframe(
        raspberryClientIP,
        121, // message ID for the kitchen doors
        1, // only one value
        3, // boolean
        &data,
        1 // data size 
    );
}

void MainWindow::button_deuren_restaurant_clicked() {
    bool checked = ui.restaurantDeurenKnop->isChecked();
    uint8_t data = checked;
    send_dataframe(
        raspberryClientIP,
        123, // message ID for the restaurant doors
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
        Wemos_3_IP,
        113, // message ID for the ventilator
        1, // only one value
        3, // boolean
        &data,
        1 // data size 
    );
}

void MainWindow::lichtkrant_apply_clicked() {
    QTextEdit* lichtkrantInput = findChild<QTextEdit*>("lichtkrantInput");
    QString tekst = lichtkrantInput->toPlainText();
    uint length = tekst.length();
    if(length == 0) return;
    if(length >= 1024) length = 1024;
    char data[1024];
    strncpy(data, tekst.toUtf8().constData(), length * sizeof(char));
    data[length] = '\0';
    send_dataframe(
        Wemos_3_IP,
        104,
        1, // altijd 1 voor ASCII
        4, // ASCII
        reinterpret_cast<uint8_t*>(data),
        length + 1
    );
}

void MainWindow::lichtkrant_reset_clicked() {
    QTextEdit* lichtkrantInput = findChild<QTextEdit*>("lichtkrantInput");
    lichtkrantInput->clear();
}

void MainWindow::slider_lampen_rgb_1_released() {
    // send the values of redValueSlider1, greenValueSlider1, and blueValueSlider1 
    uint8_t data[3];
    data[0] = static_cast<uint8_t>(ui.lamp1RED->value()); //red
    data[1] = static_cast<uint8_t>(ui.lamp1GREEN->value()); //green
    data[2] = static_cast<uint8_t>(ui.lamp1BLUE->value()); //blue
    send_dataframe(
        Wemos_3_IP,
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
        Wemos_3_IP,
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
            updateKeukenDeurenKnop(false);
            updateRestaurantDeurenKnop(false);
        }
        grenswaardeCO2Overschreden = (co2 > 900);
        if (grenswaardeCO2Overschreden) {
            QPalette palette = ui.co2ValueIndicator->palette();
            palette.setColor(palette.WindowText, Qt::red);
            ui.co2ValueIndicator->setPalette(palette);
            updateVentilator(true);
            updateKeukenDeurenKnop(true);
            updateRestaurantDeurenKnop(true);
        }
    }

    if (ui.tempValueIndicator) {
        ui.tempValueIndicator->display(temperature);

        if (grenswaardeTemperatureOverschreden && temperature <= 40) { // reset
            QPalette palette = ui.tempValueIndicator->palette();
            palette.setColor(palette.WindowText, Qt::black); 
            ui.tempValueIndicator->setPalette(palette);
            updateVentilator(false);
            updateKeukenDeurenKnop(false);
            updateRestaurantDeurenKnop(false);
        }
        grenswaardeTemperatureOverschreden = (temperature > 40);
        if (grenswaardeTemperatureOverschreden) {
            QPalette palette = ui.tempValueIndicator->palette();
            palette.setColor(palette.WindowText, Qt::red);
            ui.tempValueIndicator->setPalette(palette);
            updateVentilator(true);
            updateKeukenDeurenKnop(true);
            updateRestaurantDeurenKnop(true);
        }
    }

    if (ui.luchtValueIndicator) {
        ui.luchtValueIndicator->display(humidity);
    }
}


void MainWindow::updateDrukknop1(bool value) {
    if (ui.testKnopTafel1 && value) {
        ui.testKnopTafel1->togglePower();
    }
}

void MainWindow::updateDrukknop2(bool value) {
    if (ui.testKnopTafel2 && value) {
        ui.testKnopTafel2->togglePower();
    }
}

void MainWindow::updateDrukknop3(bool value) {
    if (ui.testKnopTafel3 && value) {
        ui.testKnopTafel3->togglePower();
    }
}

void MainWindow::updateVentilator(bool value) {
    if (ui.ventilatorKnop) ui.ventilatorKnop->setChecked(value);
}

void MainWindow::updateKeukenDeurenKnop(bool value) {
    if(ui.keukenDeurenKnop) ui.keukenDeurenKnop->setChecked(value);
}

void MainWindow::updateRestaurantDeurenKnop(bool value) {
    if(ui.restaurantDeurenKnop) ui.restaurantDeurenKnop->setChecked(value);
}
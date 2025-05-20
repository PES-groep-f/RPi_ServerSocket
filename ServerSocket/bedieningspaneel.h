/********************************************************************************
** Form generated from reading UI file 'bedieningspaneel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BEDIENINGSPANEEL_H
#define BEDIENINGSPANEEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "statusled.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *totaleLayout;
    QHBoxLayout *bovenkantLayout;
    QGridLayout *knoppenLayout;
    QPushButton *keukenLampenKnop;
    QPushButton *ventilatorKnop;
    QPushButton *keukenDeurenKnop;
    QPushButton *restaurantDeurenKnop;
    QHBoxLayout *RGBLayout;
    QGridLayout *sliderGrid;
    QLabel *REDLabel;
    QSlider *lamp1BLUE;
    QSlider *lamp1GREEN;
    QSlider *lamp1RED;
    QLabel *GREENLabel;
    QLabel *BLUELabel;
    QSpacerItem *SliderSpacer2;
    QSpacerItem *sliderSpacer1;
    QSlider *lamp2RED;
    QSlider *lamp2GREEN;
    QSlider *lamp2BLUE;
    QLabel *lamp1Label;
    QLabel *lamp2Label;
    QVBoxLayout *testKnoppenLayout;
    StatusLed *testKnopTafel1;
    StatusLed *testKnopTafel2;
    StatusLed *testKnopTafel3;
    QVBoxLayout *onderkantLayout;
    QFrame *line;
    QHBoxLayout *labelLayout;
    QLabel *co2Label;
    QLabel *tempLabel;
    QLabel *luchtLabel;
    QLabel *lichtkrantLabel;
    QHBoxLayout *valueIndicatorLayout;
    QLCDNumber *co2ValueIndicator;
    QLCDNumber *tempValueIndicator;
    QLCDNumber *luchtValueIndicator;
    QVBoxLayout *lichtkrantInputLayout;
    QTextEdit *lichtkrantInput;
    QDialogButtonBox *lichtkrantKnoppen;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1207, 666);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 40, 1071, 541));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(layoutWidget->sizePolicy().hasHeightForWidth());
        layoutWidget->setSizePolicy(sizePolicy1);
        totaleLayout = new QVBoxLayout(layoutWidget);
        totaleLayout->setSpacing(0);
        totaleLayout->setObjectName(QString::fromUtf8("totaleLayout"));
        totaleLayout->setContentsMargins(0, 0, 0, 0);
        bovenkantLayout = new QHBoxLayout();
        bovenkantLayout->setSpacing(0);
        bovenkantLayout->setObjectName(QString::fromUtf8("bovenkantLayout"));
        knoppenLayout = new QGridLayout();
        knoppenLayout->setSpacing(0);
        knoppenLayout->setObjectName(QString::fromUtf8("knoppenLayout"));
        keukenLampenKnop = new QPushButton(layoutWidget);
        keukenLampenKnop->setCheckable(true);
        keukenLampenKnop->setObjectName(QString::fromUtf8("keukenLampenKnop"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(keukenLampenKnop->sizePolicy().hasHeightForWidth());
        keukenLampenKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(keukenLampenKnop, 0, 0, 1, 1);

        ventilatorKnop = new QPushButton(layoutWidget);
        ventilatorKnop->setCheckable(true);
        ventilatorKnop->setObjectName(QString::fromUtf8("ventilatorKnop"));
        sizePolicy2.setHeightForWidth(ventilatorKnop->sizePolicy().hasHeightForWidth());
        ventilatorKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(ventilatorKnop, 0, 1, 1, 1);

        keukenDeurenKnop = new QPushButton(layoutWidget);
        keukenDeurenKnop->setCheckable(true);
        keukenDeurenKnop->setObjectName(QString::fromUtf8("keukenDeurenKnop"));
        sizePolicy2.setHeightForWidth(keukenDeurenKnop->sizePolicy().hasHeightForWidth());
        keukenDeurenKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(keukenDeurenKnop, 1, 0, 1, 1);

        restaurantDeurenKnop = new QPushButton(layoutWidget);
        restaurantDeurenKnop->setCheckable(true);
        restaurantDeurenKnop->setObjectName(QString::fromUtf8("restaurantDeurenKnop"));
        sizePolicy2.setHeightForWidth(restaurantDeurenKnop->sizePolicy().hasHeightForWidth());
        restaurantDeurenKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(restaurantDeurenKnop, 1, 1, 1, 1);


        bovenkantLayout->addLayout(knoppenLayout);

        RGBLayout = new QHBoxLayout();
        RGBLayout->setSpacing(0);
        RGBLayout->setObjectName(QString::fromUtf8("RGBLayout"));
        sliderGrid = new QGridLayout();
        sliderGrid->setObjectName(QString::fromUtf8("sliderGrid"));
        REDLabel = new QLabel(layoutWidget);
        REDLabel->setObjectName(QString::fromUtf8("REDLabel"));

        sliderGrid->addWidget(REDLabel, 0, 1, 1, 1);

        lamp1BLUE = new QSlider(layoutWidget);
        lamp1BLUE->setObjectName(QString::fromUtf8("lamp1BLUE"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lamp1BLUE->sizePolicy().hasHeightForWidth());
        lamp1BLUE->setSizePolicy(sizePolicy3);
        lamp1BLUE->setMaximum(255);
        lamp1BLUE->setOrientation(Qt::Vertical);

        sliderGrid->addWidget(lamp1BLUE, 1, 5, 1, 1);

        lamp1GREEN = new QSlider(layoutWidget);
        lamp1GREEN->setObjectName(QString::fromUtf8("lamp1GREEN"));
        sizePolicy3.setHeightForWidth(lamp1GREEN->sizePolicy().hasHeightForWidth());
        lamp1GREEN->setSizePolicy(sizePolicy3);
        lamp1GREEN->setMaximum(255);
        lamp1GREEN->setOrientation(Qt::Vertical);

        sliderGrid->addWidget(lamp1GREEN, 1, 3, 1, 1);

        lamp1RED = new QSlider(layoutWidget);
        lamp1RED->setObjectName(QString::fromUtf8("lamp1RED"));
        sizePolicy3.setHeightForWidth(lamp1RED->sizePolicy().hasHeightForWidth());
        lamp1RED->setSizePolicy(sizePolicy3);
        lamp1RED->setMaximum(255);
        lamp1RED->setOrientation(Qt::Vertical);

        sliderGrid->addWidget(lamp1RED, 1, 1, 1, 1);

        GREENLabel = new QLabel(layoutWidget);
        GREENLabel->setObjectName(QString::fromUtf8("GREENLabel"));

        sliderGrid->addWidget(GREENLabel, 0, 3, 1, 1);

        BLUELabel = new QLabel(layoutWidget);
        BLUELabel->setObjectName(QString::fromUtf8("BLUELabel"));

        sliderGrid->addWidget(BLUELabel, 0, 5, 1, 1);

        SliderSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        sliderGrid->addItem(SliderSpacer2, 1, 4, 3, 1);

        sliderSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        sliderGrid->addItem(sliderSpacer1, 1, 2, 3, 1);

        lamp2RED = new QSlider(layoutWidget);
        lamp2RED->setObjectName(QString::fromUtf8("lamp2RED"));
        sizePolicy3.setHeightForWidth(lamp2RED->sizePolicy().hasHeightForWidth());
        lamp2RED->setSizePolicy(sizePolicy3);
        lamp2RED->setMaximum(255);
        lamp2RED->setOrientation(Qt::Vertical);

        sliderGrid->addWidget(lamp2RED, 2, 1, 1, 1);

        lamp2GREEN = new QSlider(layoutWidget);
        lamp2GREEN->setObjectName(QString::fromUtf8("lamp2GREEN"));
        sizePolicy3.setHeightForWidth(lamp2GREEN->sizePolicy().hasHeightForWidth());
        lamp2GREEN->setSizePolicy(sizePolicy3);
        lamp2GREEN->setMaximum(255);
        lamp2GREEN->setOrientation(Qt::Vertical);

        sliderGrid->addWidget(lamp2GREEN, 2, 3, 1, 1);

        lamp2BLUE = new QSlider(layoutWidget);
        lamp2BLUE->setObjectName(QString::fromUtf8("lamp2BLUE"));
        sizePolicy3.setHeightForWidth(lamp2BLUE->sizePolicy().hasHeightForWidth());
        lamp2BLUE->setSizePolicy(sizePolicy3);
        lamp2BLUE->setMaximum(255);
        lamp2BLUE->setOrientation(Qt::Vertical);

        sliderGrid->addWidget(lamp2BLUE, 2, 5, 1, 1);

        lamp1Label = new QLabel(layoutWidget);
        lamp1Label->setObjectName(QString::fromUtf8("lamp1Label"));

        sliderGrid->addWidget(lamp1Label, 1, 0, 1, 1);

        lamp2Label = new QLabel(layoutWidget);
        lamp2Label->setObjectName(QString::fromUtf8("lamp2Label"));

        sliderGrid->addWidget(lamp2Label, 2, 0, 1, 1);


        RGBLayout->addLayout(sliderGrid);

        testKnoppenLayout = new QVBoxLayout();
        testKnoppenLayout->setSpacing(0);
        testKnoppenLayout->setObjectName(QString::fromUtf8("testKnoppenLayout"));
        testKnopTafel1 = new StatusLed(layoutWidget);
        testKnopTafel1->setObjectName(QString::fromUtf8("testKnopTafel1"));
        sizePolicy2.setHeightForWidth(testKnopTafel1->sizePolicy().hasHeightForWidth());
        testKnopTafel1->setSizePolicy(sizePolicy2);

        testKnoppenLayout->addWidget(testKnopTafel1);

        testKnopTafel2 = new StatusLed(layoutWidget);
        testKnopTafel2->setObjectName(QString::fromUtf8("testKnopTafel2"));
        sizePolicy2.setHeightForWidth(testKnopTafel2->sizePolicy().hasHeightForWidth());
        testKnopTafel2->setSizePolicy(sizePolicy2);

        testKnoppenLayout->addWidget(testKnopTafel2);

        testKnopTafel3 = new StatusLed(layoutWidget);
        testKnopTafel3->setObjectName(QString::fromUtf8("testKnopTafel3"));
        sizePolicy2.setHeightForWidth(testKnopTafel3->sizePolicy().hasHeightForWidth());
        testKnopTafel3->setSizePolicy(sizePolicy2);

        testKnoppenLayout->addWidget(testKnopTafel3);


        RGBLayout->addLayout(testKnoppenLayout);


        bovenkantLayout->addLayout(RGBLayout);


        totaleLayout->addLayout(bovenkantLayout);

        onderkantLayout = new QVBoxLayout();
        onderkantLayout->setSpacing(0);
        onderkantLayout->setObjectName(QString::fromUtf8("onderkantLayout"));
        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy4);
        line->setLineWidth(15);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        onderkantLayout->addWidget(line);

        labelLayout = new QHBoxLayout();
        labelLayout->setObjectName(QString::fromUtf8("labelLayout"));
        co2Label = new QLabel(layoutWidget);
        co2Label->setObjectName(QString::fromUtf8("co2Label"));
        sizePolicy1.setHeightForWidth(co2Label->sizePolicy().hasHeightForWidth());
        co2Label->setSizePolicy(sizePolicy1);
        co2Label->setAlignment(Qt::AlignCenter);

        labelLayout->addWidget(co2Label);

        tempLabel = new QLabel(layoutWidget);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        sizePolicy1.setHeightForWidth(tempLabel->sizePolicy().hasHeightForWidth());
        tempLabel->setSizePolicy(sizePolicy1);
        tempLabel->setAlignment(Qt::AlignCenter);

        labelLayout->addWidget(tempLabel);

        luchtLabel = new QLabel(layoutWidget);
        luchtLabel->setObjectName(QString::fromUtf8("luchtLabel"));
        sizePolicy1.setHeightForWidth(luchtLabel->sizePolicy().hasHeightForWidth());
        luchtLabel->setSizePolicy(sizePolicy1);
        luchtLabel->setAlignment(Qt::AlignCenter);

        labelLayout->addWidget(luchtLabel);

        lichtkrantLabel = new QLabel(layoutWidget);
        lichtkrantLabel->setObjectName(QString::fromUtf8("lichtkrantLabel"));
        sizePolicy1.setHeightForWidth(lichtkrantLabel->sizePolicy().hasHeightForWidth());
        lichtkrantLabel->setSizePolicy(sizePolicy1);
        lichtkrantLabel->setAlignment(Qt::AlignCenter);

        labelLayout->addWidget(lichtkrantLabel);


        onderkantLayout->addLayout(labelLayout);

        valueIndicatorLayout = new QHBoxLayout();
        valueIndicatorLayout->setSpacing(0);
        valueIndicatorLayout->setObjectName(QString::fromUtf8("valueIndicatorLayout"));
        co2ValueIndicator = new QLCDNumber(layoutWidget);
        co2ValueIndicator->setObjectName(QString::fromUtf8("co2ValueIndicator"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(co2ValueIndicator->sizePolicy().hasHeightForWidth());
        co2ValueIndicator->setSizePolicy(sizePolicy5);

        valueIndicatorLayout->addWidget(co2ValueIndicator);

        tempValueIndicator = new QLCDNumber(layoutWidget);
        tempValueIndicator->setObjectName(QString::fromUtf8("tempValueIndicator"));
        sizePolicy5.setHeightForWidth(tempValueIndicator->sizePolicy().hasHeightForWidth());
        tempValueIndicator->setSizePolicy(sizePolicy5);

        valueIndicatorLayout->addWidget(tempValueIndicator);

        luchtValueIndicator = new QLCDNumber(layoutWidget);
        luchtValueIndicator->setObjectName(QString::fromUtf8("luchtValueIndicator"));
        sizePolicy5.setHeightForWidth(luchtValueIndicator->sizePolicy().hasHeightForWidth());
        luchtValueIndicator->setSizePolicy(sizePolicy5);

        valueIndicatorLayout->addWidget(luchtValueIndicator);

        lichtkrantInputLayout = new QVBoxLayout();
        lichtkrantInputLayout->setSpacing(0);
        lichtkrantInputLayout->setObjectName(QString::fromUtf8("lichtkrantInputLayout"));
        lichtkrantInput = new QTextEdit(layoutWidget);
        lichtkrantInput->setObjectName(QString::fromUtf8("lichtkrantInput"));
        sizePolicy5.setHeightForWidth(lichtkrantInput->sizePolicy().hasHeightForWidth());
        lichtkrantInput->setSizePolicy(sizePolicy5);

        lichtkrantInputLayout->addWidget(lichtkrantInput);

        lichtkrantKnoppen = new QDialogButtonBox(layoutWidget);
        lichtkrantKnoppen->setObjectName(QString::fromUtf8("lichtkrantKnoppen"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lichtkrantKnoppen->sizePolicy().hasHeightForWidth());
        lichtkrantKnoppen->setSizePolicy(sizePolicy6);
        lichtkrantKnoppen->setLayoutDirection(Qt::RightToLeft);
        lichtkrantKnoppen->setOrientation(Qt::Horizontal);
        lichtkrantKnoppen->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Reset);
        lichtkrantKnoppen->setCenterButtons(true);

        lichtkrantInputLayout->addWidget(lichtkrantKnoppen);


        valueIndicatorLayout->addLayout(lichtkrantInputLayout);


        onderkantLayout->addLayout(valueIndicatorLayout);


        totaleLayout->addLayout(onderkantLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1207, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        keukenLampenKnop->setText(QCoreApplication::translate("MainWindow", "Lampen Keuken Aan / Uit", nullptr));
        ventilatorKnop->setText(QCoreApplication::translate("MainWindow", "Ventilator Aan / Uit", nullptr));
        keukenDeurenKnop->setText(QCoreApplication::translate("MainWindow", "Deuren Keuken Open / Dicht", nullptr));
        restaurantDeurenKnop->setText(QCoreApplication::translate("MainWindow", "Deuren Restaurant Open / Dicht", nullptr));
        REDLabel->setText(QCoreApplication::translate("MainWindow", "RED", nullptr));
        GREENLabel->setText(QCoreApplication::translate("MainWindow", "GREEN", nullptr));
        BLUELabel->setText(QCoreApplication::translate("MainWindow", "BLUE", nullptr));
        lamp1Label->setText(QCoreApplication::translate("MainWindow", "Lamp1", nullptr));
        lamp2Label->setText(QCoreApplication::translate("MainWindow", "Lamp2", nullptr));
        testKnopTafel1->setText(QCoreApplication::translate("MainWindow", "Drukknop Tafel 1", nullptr));
        testKnopTafel2->setText(QCoreApplication::translate("MainWindow", "Drukknop Tafel 2", nullptr));
        testKnopTafel3->setText(QCoreApplication::translate("MainWindow", "Drukknop Tafel 3", nullptr));
        co2Label->setText(QCoreApplication::translate("MainWindow", "CO2 Gehalte", nullptr));
        tempLabel->setText(QCoreApplication::translate("MainWindow", "Temperatuur (\302\260C)", nullptr));
        luchtLabel->setText(QCoreApplication::translate("MainWindow", "Luchtvochtigheid", nullptr));
        lichtkrantLabel->setText(QCoreApplication::translate("MainWindow", "Lichtkrant Informatie:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BEDIENINGSPANEEL_H
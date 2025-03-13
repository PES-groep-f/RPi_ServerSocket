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
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QSplitter *RGBSpacer;
    QWidget *layoutWidget_2;
    QVBoxLayout *bovenkantRGBLayout;
    QComboBox *RGBLampSelectie;
    QGridLayout *valueRGBLayout;
    QLabel *redLabel;
    QLabel *greenLabel;
    QLabel *blueLabel;
    QLCDNumber *redValueIndicator;
    QLCDNumber *greenValueIndicator;
    QLCDNumber *blueValueIndicator;
    QWidget *layoutWidget_3;
    QHBoxLayout *sliderLayout;
    QSlider *redValueSlider;
    QSpacerItem *horizontalSpacer;
    QSlider *greenValueSlider;
    QSpacerItem *horizontalSpacer_2;
    QSlider *blueValueSlider;
    QVBoxLayout *testKnoppenLayout;
    QPushButton *testKnopTafel1;
    QPushButton *testKnopTafel2;
    QPushButton *testKnopTafel3;
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
        keukenLampenKnop->setObjectName(QString::fromUtf8("keukenLampenKnop"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(keukenLampenKnop->sizePolicy().hasHeightForWidth());
        keukenLampenKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(keukenLampenKnop, 0, 0, 1, 1);

        ventilatorKnop = new QPushButton(layoutWidget);
        ventilatorKnop->setObjectName(QString::fromUtf8("ventilatorKnop"));
        sizePolicy2.setHeightForWidth(ventilatorKnop->sizePolicy().hasHeightForWidth());
        ventilatorKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(ventilatorKnop, 0, 1, 1, 1);

        keukenDeurenKnop = new QPushButton(layoutWidget);
        keukenDeurenKnop->setObjectName(QString::fromUtf8("keukenDeurenKnop"));
        sizePolicy2.setHeightForWidth(keukenDeurenKnop->sizePolicy().hasHeightForWidth());
        keukenDeurenKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(keukenDeurenKnop, 1, 0, 1, 1);

        restaurantDeurenKnop = new QPushButton(layoutWidget);
        restaurantDeurenKnop->setObjectName(QString::fromUtf8("restaurantDeurenKnop"));
        sizePolicy2.setHeightForWidth(restaurantDeurenKnop->sizePolicy().hasHeightForWidth());
        restaurantDeurenKnop->setSizePolicy(sizePolicy2);

        knoppenLayout->addWidget(restaurantDeurenKnop, 1, 1, 1, 1);


        bovenkantLayout->addLayout(knoppenLayout);

        RGBLayout = new QHBoxLayout();
        RGBLayout->setSpacing(0);
        RGBLayout->setObjectName(QString::fromUtf8("RGBLayout"));
        RGBSpacer = new QSplitter(layoutWidget);
        RGBSpacer->setObjectName(QString::fromUtf8("RGBSpacer"));
        RGBSpacer->setOrientation(Qt::Vertical);
        layoutWidget_2 = new QWidget(RGBSpacer);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        bovenkantRGBLayout = new QVBoxLayout(layoutWidget_2);
        bovenkantRGBLayout->setSpacing(0);
        bovenkantRGBLayout->setObjectName(QString::fromUtf8("bovenkantRGBLayout"));
        bovenkantRGBLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        bovenkantRGBLayout->setContentsMargins(0, 0, 0, 0);
        RGBLampSelectie = new QComboBox(layoutWidget_2);
        RGBLampSelectie->addItem(QString());
        RGBLampSelectie->addItem(QString());
        RGBLampSelectie->addItem(QString());
        RGBLampSelectie->setObjectName(QString::fromUtf8("RGBLampSelectie"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(RGBLampSelectie->sizePolicy().hasHeightForWidth());
        RGBLampSelectie->setSizePolicy(sizePolicy3);
        RGBLampSelectie->setLayoutDirection(Qt::LeftToRight);
        RGBLampSelectie->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        bovenkantRGBLayout->addWidget(RGBLampSelectie);

        valueRGBLayout = new QGridLayout();
        valueRGBLayout->setSpacing(0);
        valueRGBLayout->setObjectName(QString::fromUtf8("valueRGBLayout"));
        redLabel = new QLabel(layoutWidget_2);
        redLabel->setObjectName(QString::fromUtf8("redLabel"));
        sizePolicy1.setHeightForWidth(redLabel->sizePolicy().hasHeightForWidth());
        redLabel->setSizePolicy(sizePolicy1);
        redLabel->setAlignment(Qt::AlignCenter);

        valueRGBLayout->addWidget(redLabel, 0, 0, 1, 1);

        greenLabel = new QLabel(layoutWidget_2);
        greenLabel->setObjectName(QString::fromUtf8("greenLabel"));
        sizePolicy.setHeightForWidth(greenLabel->sizePolicy().hasHeightForWidth());
        greenLabel->setSizePolicy(sizePolicy);
        greenLabel->setAlignment(Qt::AlignCenter);

        valueRGBLayout->addWidget(greenLabel, 0, 1, 1, 1);

        blueLabel = new QLabel(layoutWidget_2);
        blueLabel->setObjectName(QString::fromUtf8("blueLabel"));
        sizePolicy.setHeightForWidth(blueLabel->sizePolicy().hasHeightForWidth());
        blueLabel->setSizePolicy(sizePolicy);
        blueLabel->setAlignment(Qt::AlignCenter);

        valueRGBLayout->addWidget(blueLabel, 0, 2, 1, 1);

        redValueIndicator = new QLCDNumber(layoutWidget_2);
        redValueIndicator->setObjectName(QString::fromUtf8("redValueIndicator"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(redValueIndicator->sizePolicy().hasHeightForWidth());
        redValueIndicator->setSizePolicy(sizePolicy4);

        valueRGBLayout->addWidget(redValueIndicator, 1, 0, 1, 1);

        greenValueIndicator = new QLCDNumber(layoutWidget_2);
        greenValueIndicator->setObjectName(QString::fromUtf8("greenValueIndicator"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(greenValueIndicator->sizePolicy().hasHeightForWidth());
        greenValueIndicator->setSizePolicy(sizePolicy5);
        greenValueIndicator->setLayoutDirection(Qt::LeftToRight);
        greenValueIndicator->setDigitCount(5);
        greenValueIndicator->setSegmentStyle(QLCDNumber::Filled);

        valueRGBLayout->addWidget(greenValueIndicator, 1, 1, 1, 1);

        blueValueIndicator = new QLCDNumber(layoutWidget_2);
        blueValueIndicator->setObjectName(QString::fromUtf8("blueValueIndicator"));
        sizePolicy4.setHeightForWidth(blueValueIndicator->sizePolicy().hasHeightForWidth());
        blueValueIndicator->setSizePolicy(sizePolicy4);

        valueRGBLayout->addWidget(blueValueIndicator, 1, 2, 1, 1);


        bovenkantRGBLayout->addLayout(valueRGBLayout);

        RGBSpacer->addWidget(layoutWidget_2);
        layoutWidget_3 = new QWidget(RGBSpacer);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        sliderLayout = new QHBoxLayout(layoutWidget_3);
        sliderLayout->setSpacing(0);
        sliderLayout->setObjectName(QString::fromUtf8("sliderLayout"));
        sliderLayout->setContentsMargins(0, 0, 0, 0);
        redValueSlider = new QSlider(layoutWidget_3);
        redValueSlider->setObjectName(QString::fromUtf8("redValueSlider"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(redValueSlider->sizePolicy().hasHeightForWidth());
        redValueSlider->setSizePolicy(sizePolicy6);
        redValueSlider->setMaximum(255);
        redValueSlider->setOrientation(Qt::Vertical);

        sliderLayout->addWidget(redValueSlider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sliderLayout->addItem(horizontalSpacer);

        greenValueSlider = new QSlider(layoutWidget_3);
        greenValueSlider->setObjectName(QString::fromUtf8("greenValueSlider"));
        sizePolicy6.setHeightForWidth(greenValueSlider->sizePolicy().hasHeightForWidth());
        greenValueSlider->setSizePolicy(sizePolicy6);
        greenValueSlider->setMaximum(255);
        greenValueSlider->setOrientation(Qt::Vertical);

        sliderLayout->addWidget(greenValueSlider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sliderLayout->addItem(horizontalSpacer_2);

        blueValueSlider = new QSlider(layoutWidget_3);
        blueValueSlider->setObjectName(QString::fromUtf8("blueValueSlider"));
        sizePolicy6.setHeightForWidth(blueValueSlider->sizePolicy().hasHeightForWidth());
        blueValueSlider->setSizePolicy(sizePolicy6);
        blueValueSlider->setMaximum(255);
        blueValueSlider->setOrientation(Qt::Vertical);

        sliderLayout->addWidget(blueValueSlider);

        RGBSpacer->addWidget(layoutWidget_3);

        RGBLayout->addWidget(RGBSpacer);

        testKnoppenLayout = new QVBoxLayout();
        testKnoppenLayout->setSpacing(0);
        testKnoppenLayout->setObjectName(QString::fromUtf8("testKnoppenLayout"));
        testKnopTafel1 = new QPushButton(layoutWidget);
        testKnopTafel1->setObjectName(QString::fromUtf8("testKnopTafel1"));
        sizePolicy2.setHeightForWidth(testKnopTafel1->sizePolicy().hasHeightForWidth());
        testKnopTafel1->setSizePolicy(sizePolicy2);

        testKnoppenLayout->addWidget(testKnopTafel1);

        testKnopTafel2 = new QPushButton(layoutWidget);
        testKnopTafel2->setObjectName(QString::fromUtf8("testKnopTafel2"));
        sizePolicy2.setHeightForWidth(testKnopTafel2->sizePolicy().hasHeightForWidth());
        testKnopTafel2->setSizePolicy(sizePolicy2);

        testKnoppenLayout->addWidget(testKnopTafel2);

        testKnopTafel3 = new QPushButton(layoutWidget);
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
        sizePolicy5.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy5);
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
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(co2ValueIndicator->sizePolicy().hasHeightForWidth());
        co2ValueIndicator->setSizePolicy(sizePolicy7);

        valueIndicatorLayout->addWidget(co2ValueIndicator);

        tempValueIndicator = new QLCDNumber(layoutWidget);
        tempValueIndicator->setObjectName(QString::fromUtf8("tempValueIndicator"));
        sizePolicy7.setHeightForWidth(tempValueIndicator->sizePolicy().hasHeightForWidth());
        tempValueIndicator->setSizePolicy(sizePolicy7);

        valueIndicatorLayout->addWidget(tempValueIndicator);

        luchtValueIndicator = new QLCDNumber(layoutWidget);
        luchtValueIndicator->setObjectName(QString::fromUtf8("luchtValueIndicator"));
        sizePolicy7.setHeightForWidth(luchtValueIndicator->sizePolicy().hasHeightForWidth());
        luchtValueIndicator->setSizePolicy(sizePolicy7);

        valueIndicatorLayout->addWidget(luchtValueIndicator);

        lichtkrantInputLayout = new QVBoxLayout();
        lichtkrantInputLayout->setSpacing(0);
        lichtkrantInputLayout->setObjectName(QString::fromUtf8("lichtkrantInputLayout"));
        lichtkrantInput = new QTextEdit(layoutWidget);
        lichtkrantInput->setObjectName(QString::fromUtf8("lichtkrantInput"));
        sizePolicy7.setHeightForWidth(lichtkrantInput->sizePolicy().hasHeightForWidth());
        lichtkrantInput->setSizePolicy(sizePolicy7);

        lichtkrantInputLayout->addWidget(lichtkrantInput);

        lichtkrantKnoppen = new QDialogButtonBox(layoutWidget);
        lichtkrantKnoppen->setObjectName(QString::fromUtf8("lichtkrantKnoppen"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(lichtkrantKnoppen->sizePolicy().hasHeightForWidth());
        lichtkrantKnoppen->setSizePolicy(sizePolicy8);
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
        RGBLampSelectie->setItemText(0, QCoreApplication::translate("MainWindow", "RGB Lamp 1", nullptr));
        RGBLampSelectie->setItemText(1, QCoreApplication::translate("MainWindow", "RGB Lamp 2", nullptr));
        RGBLampSelectie->setItemText(2, QCoreApplication::translate("MainWindow", "RGB Lamp 3", nullptr));

        redLabel->setText(QCoreApplication::translate("MainWindow", "RED", nullptr));
        greenLabel->setText(QCoreApplication::translate("MainWindow", "GREEN", nullptr));
        blueLabel->setText(QCoreApplication::translate("MainWindow", "BLUE", nullptr));
        testKnopTafel1->setText(QCoreApplication::translate("MainWindow", "Test Drukknop Tafel 1", nullptr));
        testKnopTafel2->setText(QCoreApplication::translate("MainWindow", "Test Drukknop Tafel 2", nullptr));
        testKnopTafel3->setText(QCoreApplication::translate("MainWindow", "Test Drukknop Tafel 3", nullptr));
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

#ifndef STATUSLED_H
#define STATUSLED_H

#include <QWidget>
#include <QPainter>
#include <QString>

/**
 * @class StatusLed
 * @brief Een eenvoudige LED-statusindicator met tekstlabel.
 *
 * Deze klasse toont een cirkelvormige LED die rood kleurt wanneer geactiveerd.
 * Daarnaast wordt een tekstlabel weergegeven naast de LED. Klikken op de widget
 * schakelt de LED uit indien deze aanstaat.
 */
class StatusLed : public QWidget {
    Q_OBJECT

    /**
     * @brief Eigenschap voor de LED-status (aan/uit).
     */
    Q_PROPERTY(bool power READ power WRITE setPower NOTIFY powerChanged)

    /**
     * @brief Eigenschap voor het tekstlabel naast de LED.
     */
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    /**
     * @brief Constructor voor de StatusLed widget.
     * @param parent De bovenliggende widget (optioneel).
     */
    explicit StatusLed(QWidget* parent = nullptr)
        : QWidget(parent), m_power(false), m_text("") {}

    /**
     * @brief Geeft de huidige status van de LED terug.
     * @return true als de LED aan staat, anders false.
     */
    bool power() const { return m_power; }

    /**
     * @brief Geeft de huidige tekst naast de LED terug.
     * @return De weergegeven tekst.
     */
    QString text() const { return m_text; }

public slots:
    /**
     * @brief Zet de status van de LED.
     * @param power true om de LED aan te zetten, false om uit te zetten.
     */
    void setPower(bool power) {
        if (power != m_power) {
            m_power = power;
            emit powerChanged();
            update();
        }
    }

    /**
     * @brief Wisselt de huidige status van de LED (aan ⇄ uit).
     */
    void togglePower() {
        m_power = !m_power;
        emit powerChanged();
        update();
    }

    /**
     * @brief Wijzigt de weergegeven tekst naast de LED.
     * @param text De nieuwe tekst.
     */
    void setText(const QString& text) {
        if (text != m_text) {
            m_text = text;
            emit textChanged();
            update();
        }
    }

signals:
    /**
     * @brief Signaal dat wordt uitgezonden wanneer de LED-status wijzigt.
     */
    void powerChanged();

    /**
     * @brief Signaal dat wordt uitgezonden wanneer de tekst verandert.
     */
    void textChanged();

protected:
    /**
     * @brief Tekenfunctie om de LED en tekst weer te geven.
     * @param event Het paint event (wordt niet gebruikt).
     */
    virtual void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event)
        QPainter ledPainter(this);

        ledPainter.setPen(Qt::black);
        if (m_power) {
            ledPainter.setBrush(Qt::red);
        } else {
            ledPainter.setBrush(Qt::NoBrush);
        }
        QRect ledRect(10, height() / 2 - 10, 20, 20);
        ledPainter.drawEllipse(ledRect);

        ledPainter.setPen(Qt::black);
        ledPainter.setFont(QFont("Arial", 10));
        QRect textRect(40, 0, width() - 50, height());
        ledPainter.drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, m_text);
    }

    /**
     * @brief Reageert op muisklikken door de LED uit te schakelen (indien aan).
     * @param event Het mouse press event (wordt niet gebruikt).
     */
    virtual void mousePressEvent(QMouseEvent* event) override {
        Q_UNUSED(event);
        if (m_power) {
            setPower(false);
        }
    }

private:
    bool m_power;      ///< Huidige status van de LED (true = aan, false = uit).
    QString m_text;    ///< Weergegeven tekst naast de LED.
};

#endif // STATUSLED_H

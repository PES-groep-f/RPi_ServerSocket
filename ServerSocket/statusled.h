#ifndef STATUSLED_H
#define STATUSLED_H

#include <QWidget>
#include <QPainter>
#include <QString>

class StatusLed : public QWidget {
    Q_OBJECT
    Q_PROPERTY(bool power READ power WRITE setPower NOTIFY powerChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit StatusLed(QWidget* parent = nullptr)
        : QWidget(parent), m_power(false), m_text("") {}

    bool power() const { return m_power; }
    QString text() const { return m_text; }

public slots:
    void setPower(bool power) {
        if (power != m_power) {
            m_power = power;
            emit powerChanged();
            update();
        }
    }

    void setText(const QString& text) {
        if (text != m_text) {
            m_text = text;
            emit textChanged();
            update();
        }
    }

signals:
    void powerChanged();
    void textChanged();

protected:
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

private:
    bool m_power;
    QString m_text;
};

#endif // STATUSLED_H

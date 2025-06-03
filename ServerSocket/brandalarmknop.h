#ifndef BRANDALARMKNOP_H
#define BRANDALARMKNOP_H

#include <QWidget>
#include <QPainter>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QMouseEvent>

class BrandAlarmKnop : public QWidget {
    Q_OBJECT
    Q_PROPERTY(bool power READ power WRITE setPower NOTIFY powerChanged)
    Q_PROPERTY(bool active READ isActive WRITE setActive NOTIFY activeChanged)

public:
    explicit BrandAlarmKnop(QWidget* parent = nullptr)
        : QWidget(parent), m_power(false), m_active(false) {
        setMinimumSize(100, 100); // Ensure widget appears larger and square
        setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    }

    bool power() const { return m_power; }
    bool isActive() const { return m_active; }

public slots:
    void setPower(bool power) {
        if (power != m_power) {
            m_power = power;
            emit powerChanged();
            update();
        }
    }

    void setActive(bool active) {
        m_power = false;
        emit powerChanged();
        if (m_active != active) {
            m_active = active;
            emit activeChanged();
            update();
        }
    }

    void toggleActive() {
        setActive(!m_active);
    }

signals:
    void powerChanged();
    void activeChanged();

protected:
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        int side = qMin(width(), height());
        QRectF squareRect((width() - side) / 2.0, (height() - side) / 2.0, side, side);

        // Border
        painter.setPen(Qt::black);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(squareRect);

        // Glow if powered and active
        if (m_power && m_active) {
            QRadialGradient glow(squareRect.center(), side / 2.0);
            glow.setColorAt(0.0, QColor(255, 0, 0, 200));  // Bright center
            glow.setColorAt(1.0, QColor(255, 0, 0, 20));   // Soft outer glow
            painter.setBrush(glow);
            painter.drawRect(squareRect);
        }

        // Red cross if not active
        if (!m_active) {
            QPen crossPen(QColor(200, 0, 0), 4);
            painter.setPen(crossPen);

            const int margin = side * 0.2;
            QPointF topLeft(squareRect.topLeft() + QPointF(margin, margin));
            QPointF bottomRight(squareRect.bottomRight() - QPointF(margin, margin));
            QPointF topRight(squareRect.topRight() + QPointF(-margin, margin));
            QPointF bottomLeft(squareRect.bottomLeft() + QPointF(margin, -margin));

            painter.drawLine(topLeft, bottomRight);
            painter.drawLine(topRight, bottomLeft);
        }
    }

    void mousePressEvent(QMouseEvent* event) override {
        Q_UNUSED(event);
        toggleActive();
    }

private:
    bool m_power = false;
    bool m_active = false;
};

#endif

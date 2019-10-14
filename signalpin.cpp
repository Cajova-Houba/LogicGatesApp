#include "signalpin.h"

SignalPin::SignalPin()
{
    _outputSignal = false;
}

void SignalPin::flipOutputSignal()
{
    _outputSignal = !_outputSignal;
}

void SignalPin::draw(QPainter &painter)
{
    painter.setPen(QPen(QColor(0,0,0)));

    painter.drawLine(0, 50, 30, 50);

    if (outputSignal()) {
        painter.setPen(QPen(QColor(255,0,0)));
    }
    painter.drawEllipse(30, 45, 10, 10);
    if (outputSignal()) {
        painter.setPen(QPen(QColor(0,0,0)));
    }

    painter.drawText(20, 40, outputSignal() ? "1" : "0");
}

bool SignalPin::clickedOn(QPoint clickPoint)
{
    return clickPoint.x() >= 0 && clickPoint.x() <= 50 &&
            clickPoint.y() >= 45 && clickPoint.y() <= 55;
}

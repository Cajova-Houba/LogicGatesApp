#ifndef SIGNALPIN_H
#define SIGNALPIN_H

#include <QPainter>


/**
 * @brief SignalPin::SignalPin Pin which omits logical signal.
 */
class SignalPin
{
public:
    SignalPin();

    /**
     * @brief outputSignal Returns the output signal of this pin.
     * @return Output of this pin.
     */
    bool outputSignal() { return _outputSignal; }

    /**
     * @brief outputSignal Sets output signal of this pin.
     * @param value Output signal of this pin.
     */
    void outputSignal(bool value) { _outputSignal = value; }

    /**
     * @brief flipOutputSignal Negates current output signal.
     */
    void flipOutputSignal();

    /**
     * Uses painter object to draw itself.
     *
     * @brief draw Draws itself.
     * @param painter Object used to draw itself.
     * @param baseX Base X coordinate of this pin.
     * @param baseY Base Y coordinate of this pin.
     */
    void draw(QPainter& painter);

    /**
     * @brief clickedOn Returns true if clickPoint is on this pin.
     * @param clickPoint
     * @return
     */
    bool clickedOn(QPoint clickPoint);

private:
    bool _outputSignal;
};

#endif // SIGNALPIN_H

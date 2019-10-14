#ifndef BASELOGICGATE_H
#define BASELOGICGATE_H

#include <QPainter>

class BaseLogicGate
{
public:

    /**
     * Uses painter object to draw itself.
     *
     * @brief draw Draws itself.
     * @param painter Object used to draw itself.
     * @param baseX Base X coordinate of this gate.
     * @param baseY Base Y coordinate of this gate.
     */
    virtual void draw(QPainter& painter) = 0;

    /**
     * @brief clickedOn Returns true if the mouse click is in the area of this gate.
     * @param clickPosition Position of click.
     * @return True if the gate was clickend on.
     */
    virtual bool clickedOn(QPoint clickPosition) = 0;

    /**
     * @brief clickAndSelect If the clickedOn returns true, selects/deselects the gate. Otherwise nothing happnes.
     * @param clickPosition Position of click.
     * @return True if the gate was clicked on.
     */
    virtual bool clickAndSelect(QPoint clickPosition) = 0;

    /**
     * @brief calculateOutput Calculates output of this gate based on its inputs.
     * @return Output of this gate.
     */
    virtual bool calculateOutput() = 0;

protected:

    const int lineWidth = 20;
    const int width = 50;
    const int height = 100;
};

#endif // BASELOGICGATE_H

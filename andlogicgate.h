#ifndef ANDLOGICGATE_H
#define ANDLOGICGATE_H

#include "baselogicgate.h"

class AndLogicGate : public BaseLogicGate
{
public:
    AndLogicGate();

    void draw(QPainter& painter) override;
    bool clickedOn(QPoint clickPosition) override;
    bool clickAndSelect(QPoint clickPosition) override;
    void select();
    void deselect();
    bool isSelected();

    /**
     * @brief place Places this gate (sets its top left position) to the given point.
     * @param newPosition New position (top left corner of enclosing rectangle).
     */
    void place(QPoint newPosition);

    bool calculateOutput() override;

private:
    bool selected;

    /**
     * @brief clickCursorPosition Position where the cursor has clicked on the gate when selecting it. Relative to the top left corner.
     */
    QPoint clickCursorPosition;

    /**
     * @brief position Top left corner of the rectangle enclosing the gate
     */
    QPoint position;
};

#endif // ANDLOGICGATE_H

#include "andlogicgate.h"

AndLogicGate::AndLogicGate()
{
    selected = false;
    position.setX(0);
    position.setY(0);

    clickCursorPosition.setX(0);
    clickCursorPosition.setY(0);
}

void AndLogicGate::draw(QPainter& painter)
{
    int baseX = position.x();
    int baseY = position.y();

    if(selected) {
        painter.setPen(QPen(QColor(255,0,0)));
    }

    // gate body
    painter.drawRect(QRect(baseX + lineWidth,
                           baseY,
                           width,
                           height));
    painter.drawText(baseX + 40,
                     baseY + 40,
                     "&");
    painter.setPen(QPen(QColor(0,0,0)));


    // gate inputs
    painter.drawLine(baseX,
                     baseY + 20,
                     baseX + lineWidth,
                     baseY + 20);
    painter.drawLine(baseX,
                     baseY + 80,
                     baseX + lineWidth,
                     baseY + 80);

    // gate output
    painter.drawLine(baseX + lineWidth + width,
                     baseY + height/2,
                     baseX + lineWidth + width + lineWidth,
                     baseY + height/2);
}

bool AndLogicGate::clickedOn(QPoint clickPosition)
{
    // the gate is in rectangle 2*lineWidth + width x height
    int clickX = clickPosition.x();
    int clickY = clickPosition.y();

    return (clickX >= position.x() && clickX <= (position.x() + width + 2*lineWidth))
            && (clickY >= position.y() && clickY <= (position.y() + height));
}

bool AndLogicGate::clickAndSelect(QPoint clickPosition)
{
    if (clickedOn(clickPosition)) {
        if (selected) {
            deselect();
        } else {
            // calculate the difference between clickPosition and top left corner of this gate
            clickCursorPosition.setX(clickPosition.x() - position.x());
            clickCursorPosition.setY(clickPosition.y() - position.y());
            select();
        }
        return true;
    }

    return false;
}

void AndLogicGate::select()
{
    selected = true;
}

void AndLogicGate::deselect()
{
    selected = false;
    clickCursorPosition.setX(0);
    clickCursorPosition.setY(0);
}

bool AndLogicGate::isSelected()
{
    return selected;
}

void AndLogicGate::place(QPoint newPosition)
{
    if (selected) {
        position.setX(newPosition.x() - clickCursorPosition.x());
        position.setY(newPosition.y() - clickCursorPosition.y());
    } else {
        position.setX(newPosition.x());
        position.setY(newPosition.y());
    }
}

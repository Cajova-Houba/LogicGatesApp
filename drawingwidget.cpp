#include "drawingwidget.h"

DrawingWidget::DrawingWidget(QWidget *parent) : QWidget(parent)
{
    drag = false;
    gatePlaced = false;
}

void DrawingWidget::mousePressEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button()
            && !drag
            && andLogicGate.clickAndSelect(event->pos())) {
        drag = true;
    }
}

void DrawingWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button()) {
        QPoint clickPosition = event->pos();

        // drag -> release drag, place gate and deselect
        if (drag) {
            drag = false;
            andLogicGate.place(clickPosition);
            andLogicGate.deselect();
        } else if (!gatePlaced) {
            // no drag and gate is not placed yet => place gate
            andLogicGate.place(clickPosition);
            gatePlaced = true;
        }

        drawGate();
    }
}

void DrawingWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (drag) {
        andLogicGate.place(event->pos());
        drawGate();
    }
}

void DrawingWidget::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
            int newWidth = qMax(width() + 128, image.width());
            int newHeight = qMax(height() + 128, image.height());
            resizeImage(&image, QSize(newWidth, newHeight));
            update();
        }
    QWidget::resizeEvent(event);
}

void DrawingWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void DrawingWidget::drawGate()
{
    QPainter painter(&image);
    image.fill(qRgb(255,255,255));
    andLogicGate.draw(painter);
    update();
}

void DrawingWidget::resizeImage(QImage *image, const QSize &newSize)
{

    if (image->size() == newSize) {
        return;
    }

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

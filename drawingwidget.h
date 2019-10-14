#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QImage>
#include <QSize>
#include "andlogicgate.h"
#include "signalpin.h"

class DrawingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:

    /**
     * @brief showEvent Kind of init. Draw signal pin(s).
     * @param event
     */
    void showEvent(QShowEvent *event) override;

    /**
     * @brief mouseDoubleClickEvent Flip signal pint output on double click.
     * @param event
     */
    void mouseDoubleClickEvent(QMouseEvent *event) override;

    /**
     * @brief mousePressEvent If some gate is selected, dragging starts.
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief mouseReleaseEvent New gate is drawn or existing gate is selected on mouse release.
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

    /**
     * @brief mouseMoveEvent Dragged gate is redrawn on mouse move.
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief resizeEvent Image is resized on widget resize.
     * @param event
     */
    void resizeEvent(QResizeEvent *event) override;

    /**
     * @brief paintEvent Paint event to draw image on widget.
     * @param event
     */
    void paintEvent(QPaintEvent *event) override;

private:

    /**
     * @brief clearImage Clears the buffer image and draws signal pin on it.
     */
    void clearImage();

    /**
     * @brief drawGate Draws gate on given base point.
     * @param basePoint Base point for logic gate.
     */
    void drawGate();

    /**
     * @brief drawPin Draws signal pin.
     * @param pin Pin to be drawn.
     */
    void drawPin(SignalPin& pin);

    /**
     * @brief resizeImage Resize the image object to fit the widget size.
     * @param image Image to resize.
     * @param newSize Size to resize image to.
     */
    void resizeImage(QImage *image, const QSize &newSize);

    bool drag;
    bool gatePlaced;
    QImage image;
    AndLogicGate andLogicGate;
    SignalPin signalPin;
};

#endif // DRAWINGWIDGET_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QCursor>
#include <QLabel>
#include <QMouseEvent>
#include "andlogicgate.h"
#include "drawingwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AndLogicGate andGate;

    DrawingWidget* drawingWidget;

    void printCursorPosition();

    void drawGates();
};
#endif // MAINWINDOW_H

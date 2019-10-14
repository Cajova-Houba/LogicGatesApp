#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , drawingWidget(new DrawingWidget(this))
{
    setCentralWidget(drawingWidget);

    resize(500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printCursorPosition()
{
    QLabel* label = ui->centralwidget->findChild<QLabel*>("cursorPositionLabel");
    std::stringstream ss;
    QPoint currentPos = QWidget::mapFromGlobal(QCursor::pos());
    ss << currentPos.x() << " : " << currentPos.y();
    label->setText(QString::fromStdString(ss.str()));
}

void MainWindow::drawGates()
{
//    QPainter painter(this);
//    QPoint currentPos = QWidget::mapFromGlobal(QCursor::pos());
//    this->andGate.draw(painter, currentPos.x(), currentPos.y());
}


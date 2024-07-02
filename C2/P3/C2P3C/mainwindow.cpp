#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
# include <QBrush>
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rectView->setScene(&scene);
    rectangle = new QGraphicsRectItem(0,0, 40,30);
    scene.addItem(rectangle);
    rectangle->setBrush(Qt::black);
    connect(&myTimer,SIGNAL(timeout()), this, SLOT(myTimeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myTimeout() {
    rectangle -> setBrush(Qt::black);
    myTimer.stop();
}

void MainWindow::on_timbreBtn_clicked()
{
    myTimer.start(2000);
    rectangle->setBrush(Qt::yellow);
}

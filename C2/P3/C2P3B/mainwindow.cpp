#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rectView->setScene(&scene);
    rectangle=scene.addRect(0,0,40,30);
    rectangle->setBrush(Qt::black);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_timbreBtn_clicked()
{
    rectangle->setBrush(Qt::yellow);
}

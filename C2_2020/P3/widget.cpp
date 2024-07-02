#include <iostream>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    rect = new RectangleMove(0,0,30,30);
    scene->addItem(rect);
    connect(ui->up,SIGNAL(pressed()),this,SLOT(up()));
    connect(ui->up,SIGNAL(released()),this,SLOT(released()));

}


void Widget::up(){
    connect(this->timer,SIGNAL(timeout()),rect,SLOT(up()));
    this->timer->start(100);
}

void Widget::released(){
    disconnect(timer,SIGNAL(timeout()),nullptr,nullptr);
    this->timer->stop();
}

Widget::~Widget()
{
    delete ui;
    delete scene;
    delete timer;
    delete rect;
}


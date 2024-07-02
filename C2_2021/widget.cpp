#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    series = new QScatterSeries();

    chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Random Points");
    ui->graphicsView->setChart(chart);

    timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(addPoint()));

}

void Widget::addPoint(){
    QRandomGenerator rand = QRandomGenerator::securelySeeded();
    series->append(rand.generateDouble(), rand.generateDouble());
}


Widget::~Widget()
{
    delete ui;
}


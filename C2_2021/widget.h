#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtCharts>
#include<QChartView>
#include<QScatterSeries>
#include <QRandomGenerator>

using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void addPoint();

private:
    Ui::Widget *ui;
    QScatterSeries *series;
    QChart *chart;
    QTimer *timer;
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "rectanglemove.h"

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
    void released();
    void up();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    RectangleMove *rect;
    QTimer *timer = new QTimer(this);
};
#endif // WIDGET_H

#ifndef RECTANGLEMOVE_H
#define RECTANGLEMOVE_H

#include <QGraphicsRectItem>


class RectangleMove:public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    RectangleMove(int x, int y, int w, int h);

public slots:
    void up();

};

#endif // RECTANGLEMOVE_H

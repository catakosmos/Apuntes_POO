#ifndef SQUARECOLOR_H
#define SQUARECOLOR_H

#include <QWidget>
#include <QColor>

class SquareColor : public QWidget
{
    Q_OBJECT

public:
    SquareColor(QWidget * parent = nullptr);

    void checkCollision();
    void changeCircleColor(const QColor &color);

public slots:
    void changeColor();

protected:  // event handler methods
    void paintEvent(QPaintEvent * event);
    void keyPressEvent(QKeyEvent * event);

private:
    QColor currentColor;
    int xPos, yPos;
    QColor originalColor;
    QColor circleColor;
    int circleRadius;
};

#endif // SQUARECOLOR_H

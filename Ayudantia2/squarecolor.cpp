# include "squarecolor.h"
# include <QPainter>
# include <QKeyEvent>
# include <cstdlib>  // util para generar semilla en base al tiempo
# include <ctime>
#include <QImage>

// Implementacion

// constructor:
SquareColor::SquareColor(QWidget *parent): QWidget(parent), currentColor(Qt::red), xPos(100), yPos(100) {
    // importantes para la interaccion con el teclado y la generacion de colores aleatorios:
    srand(static_cast<unsigned>(time(0)));  // generar semilla aleatoria
    setFocusPolicy(Qt::StrongFocus);        // asegura que colorSquare reciba los eventos de terclado
}

// metodos:
void SquareColor::changeColor(){
    currentColor = QColor(rand() % 256, rand() % 256, rand() % 256);
    update();
}

void SquareColor::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    painter.setBrush(currentColor);
    painter.drawRect(xPos, yPos, 100, 100);

    // Draw a filled circle in the center of the widget
    painter.setBrush(circleColor);
    int centerX = width() / 2;
    int centerY = height() / 2;
    painter.drawEllipse(centerX - circleRadius, centerY - circleRadius, circleRadius * 2, circleRadius * 2);

    // Draw the image in the center of the circle
    QImage image("C:/Imagenes/mascota.png");
    int imageX = centerX - image.width() / 2;
    int imageY = centerY - image.height() / 2;
    painter.drawImage(imageX, imageY, image);
}

void SquareColor::keyPressEvent(QKeyEvent * event){
    switch(event->key()){
    case Qt::Key_Up:
        yPos = std::max(0, yPos-10);
        break;
    case Qt::Key_Down:
        yPos = std::min(height()-100, yPos + 10);
        break;
    case Qt::Key_Left:
        xPos = std::max(0, xPos - 10);
        break;
    case Qt::Key_Right:
        xPos = std::min(width()-100, xPos + 10);
        break;
    }

    checkCollision();
    update();   // importante para actualizar al ocurrir el evento
}

void SquareColor::checkCollision() {
    int squareCenterX = xPos + 50;
    int squareCenterY = yPos + 50;
    int centerX = width() / 2;
    int centerY = height() / 2;
    int distance = std::sqrt(std::pow(squareCenterX - centerX, 2) + std::pow(squareCenterY - centerY, 2));

    if (distance < 50 + circleRadius) {
        changeCircleColor(currentColor);
    } else {
        changeCircleColor(Qt::white);
    }
}

void SquareColor::changeCircleColor(const QColor &color) {
    circleColor = color;
    update();
}

#include "rectanglemove.h"

RectangleMove::RectangleMove(int posX, int posY, int ancho, int alto):QGraphicsRectItem(posX,posY,ancho,alto)
{

}

void RectangleMove::up(){
    this->setY(this->y()-10);

}

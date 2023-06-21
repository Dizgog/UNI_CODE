#include "Square.h"

void Square::setTop(Point<double> topLeft)
{
    if(topLeft.x - position.x != topLeft.y - position.y)
        throw std::invalid_argument("Provided coordinates does not form a square");
    else
        Rectangle::setTop(topLeft);
}
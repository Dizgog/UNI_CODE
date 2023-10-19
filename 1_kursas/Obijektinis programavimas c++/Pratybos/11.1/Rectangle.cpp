#include "Shape.h"
#include "Point.h"
#include "Rectangle.h"

void Rectangle::setTop(Point <double> topLeft)
{
    this ->topLeft = topLeft;
}

Point <double> Rectangle::getTop() const
{
    return topLeft;
}

double Rectangle::area() const
{
    if(position.x*topLeft.y>=0)
        return position.x*topLeft.y;
    else
        return (position.x*topLeft.y)*(-1.0);
}

double Rectangle::perimeter() const
{
    if(position.x*topLeft.y>=0)
    return 2*(position.x*topLeft.x)+2*(position.y*topLeft.y);
    else
    return (2*(position.x*topLeft.x)+2*(position.y*topLeft.y))*(-1.0);
}

void Rectangle::print() const
{
    std::cout << "Right bottom of the rectangle: ";
    Shape::print();
    std::cout << "Top left of the rectangle: " << topLeft << std::endl;
}
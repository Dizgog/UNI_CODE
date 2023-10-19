#include "Circle.h"

double Circle::area() const
{
    return pi*radius*radius;
}

double Circle::perimeter() const
{
    return 2*pi*radius;
}

void Circle::print() const
{
    std::cout << "Center of the circle: ";
    Shape::print();
    std::cout << "Radius of the circle: " << radius << std::endl;
}
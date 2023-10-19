#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class Rectangle : public Shape
{
protected:
    Point<double> topLeft;
public:

    Rectangle(Point<double> position, Point<double> topLeft)
        :Shape(position)
    {
        setTop(topLeft);
    }
    Rectangle(Point<double> position, double widght, double height)
        :Shape(position)
    {
        setTop(Point<double>(position.x + widght, position.y + height));
    }

    void setTop(Point <double>);
    Point<double> getTop() const;
    double area() const;
	double perimeter() const;
    void print() const;
    void draw(SDL_Renderer* renderer) const;
};

#endif

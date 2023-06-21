#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#define pi 3.14
class Circle : public Shape
{
protected:
    double radius;
public:

    Circle(Point<double> center, double radius)
        :Shape(center), radius(radius)
        {}

    double area() const;
	double perimeter() const;
    void print() const;
    void draw(SDL_Renderer* renderer) const;
};

#endif
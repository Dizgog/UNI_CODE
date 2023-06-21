#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include <SDL2/SDL.h>
class Shape
{
protected:
    Point<double> position;
public:

    Shape(Point<double> position)
        :position(position)
    {}
    Shape(double x, double y)
		:position(x, y)
	{}

    void setPosition(Point<double> position);
    Point<double> getPosition() const;
    void print() const;
};

#endif
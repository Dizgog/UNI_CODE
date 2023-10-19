#define _USE_MATH_DEFINES
#include "Point.hpp"


Point::Point()
: x(0), y(0)   //member initialization list
{
}
    //normalus konstruktorius
Point::Point(float x_input, float y_input)
: x(x_input), y(y_input)
{
}

Point::~Point()
{
    //dtor
}

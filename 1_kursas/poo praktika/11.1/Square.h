#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

class Square : public Rectangle
{
private:

public:
    Square(Point<double> position, Point<double> topLeft)
        :Rectangle(position, topLeft)
    {
        setTop(topLeft);
    };
    
    Square(Point<double> position, double lenght)
        :Rectangle(position, lenght, lenght)
    {};

    void setTop(Point <double>); 
};



#endif
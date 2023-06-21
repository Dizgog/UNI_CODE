#include "Shape.h"
#include "Point.h"

Point<double> Shape::getPosition() const
{
	return position;
}

void Shape::setPosition(Point<double> new_position)
{
	position = new_position;
}

void Shape::print() const
{
	std::cout << position << std::endl;
}
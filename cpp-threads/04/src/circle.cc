#include "circle.h"

Circle::Circle(const int x,
			   const int y,
			   const double radius,
			   const double height)
: x(x)
, y(y)
, radius(radius)
, height(height)
{
	square = 3.14 * std::pow(radius, 2);
}

double Circle::getSquare()
{
    return square;
}
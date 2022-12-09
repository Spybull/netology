#include "rectangle.h"

Rectangle::Rectangle(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Rectangle")
{
    if ( a != c )
        throw FigureException("Can't create! Because: a side != c side");

    if ( b != d )
        throw FigureException("Can't create! Because: b side != d side");

    if ( A != 90 || B != 90 || C != 90 || D != 90 )
        throw FigureException("Can't create! Because: all angles must be 90");
}
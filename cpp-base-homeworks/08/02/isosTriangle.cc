#include "isosTriangle.h"

IsosTriangle::IsosTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "Isosceles Triangle")
{
    if ( a != c )
        throw FigureException("Can't create! Because: a side != c side");
    
    if ( A != C )
        throw FigureException("Can't create! Because: A angle != C angle");
}
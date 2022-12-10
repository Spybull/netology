#include "inc/isosTriangle.h"

IsosTriangle::IsosTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, "Isosceles Triangle")
{
    if ( a != c )
        throw FigureException(FigureExitCodes::SIDES_A_C_NOT_EQUAL);
    
    if ( A != C )
        throw FigureException(FigureExitCodes::ANGLES_A_C_NOT_EQUAL);
}
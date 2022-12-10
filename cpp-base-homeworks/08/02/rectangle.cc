#include "inc/rectangle.h"

Rectangle::Rectangle(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Rectangle")
{
    if ( a != c )
        throw FigureException(FigureExitCodes::SIDES_A_C_NOT_EQUAL);

    if ( b != d )
        throw FigureException(FigureExitCodes::SIDES_B_D_NOT_EQUAL);

    if ( A != 90 || B != 90 || C != 90 || D != 90 )
        throw FigureException(FigureExitCodes::ALL_ANGLES_NOT_EQ_90);
}
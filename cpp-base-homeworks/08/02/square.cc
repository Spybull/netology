#include "inc/square.h"

Square::Square(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Square")
{
    if (a != b || a != c || a != d || b != c || b != d || c != d)
        throw FigureException(FigureExitCodes::ALL_SIDES_NOT_EQ);

    if ( A != 90 || B != 90 || C != 90 || D != 90)
        throw FigureException(FigureExitCodes::ALL_ANGLES_NOT_EQ_90);
}
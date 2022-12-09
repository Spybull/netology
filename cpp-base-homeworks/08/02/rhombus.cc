#include "rhombus.h"

Rhombus::Rhombus(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Rhombus")
{
    if (a != b || a != c || a != d || b != c || b != d || c != d)
        throw FigureException("Can't create! Because: all sides must be equal");

    if ( A != C )
        throw FigureException("Can't create! Because: A angle != C angle");

     if ( B != D )
        throw FigureException("Can't create! Because: B angle != D angle");
}
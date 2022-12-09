#include "parallelogram.h"
Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, "Parallelogram")
{
    if ( a != c )
        throw FigureException("Can't create! Because: a side != c side");
    
    if ( b != d )
        throw FigureException("Can't create! Because: b side != d side");

     if ( A != C )
        throw FigureException("Can't create! Because: A angle != C angle");

     if ( B != D )
        throw FigureException("Can't create! Because: B angle != D angle");
}
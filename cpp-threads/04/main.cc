#include <iostream>
#include <vector>
#include <exception>
#include <memory>

#include "shape.h"
#include "square.h"

int main()
{
    //example test
    try
    {
        std::vector<Point2D> pt1 = { {2, 3}, {2, 3}, {2, 3}, {2, 3} };
        Square sq(pt1);
        sq.scaleX(5);
        sq.scaleY(5);
        sq.printPoints();

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
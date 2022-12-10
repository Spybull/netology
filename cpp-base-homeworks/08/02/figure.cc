#include "inc/figure.h"
#include "inc/exceptions.h"

Figure::Figure(int _sides_count=0)
    : Figure(_sides_count, "Figure")
{
    if (_sides_count != 0)
        throw FigureException(FigureExitCodes::SIDES_COUNT_NOT_ZERO);
}

Figure::Figure(int _sides_count, std::string _name)
        : sides_count(_sides_count)
        , name(_name)
{
    printInfo();
}

int Figure::getSidesCount() {
    return sides_count;
}

std::string Figure::getName() {
    return name;
}

void Figure::printInfo() {
    std::cout << name << " ";
}
#include "figure.h"
#include "exceptions.h"

Figure::Figure() : Figure(0, "Figure") {}

Figure::Figure(int _sides_count, std::string _name)
        : sides_count(_sides_count)
        , name(_name)
{}

int Figure::getSidesCount() {
    return sides_count;
}

std::string Figure::getName() {
    return name;
}

void Figure::printInfo() {
    std::cout << name << " ";
}
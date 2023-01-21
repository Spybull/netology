#include "eagle.h"

Eagle::Eagle(double s, std::string n) : Air(s, n) {}
Eagle::Eagle(double s) : Air(s, "Eagle") {}

void Eagle::calcTime(double d) {
    factor = 1 - (6.0 /100);
    d *= factor;
    this->fullTime = d / speed; 
}
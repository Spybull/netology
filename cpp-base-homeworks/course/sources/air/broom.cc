#include "broom.h"

Broom::Broom(double s, std::string n) : Air(s, n) {};
Broom::Broom(double s) : Air(s, "Broom") {};

void Broom::calcTime(double d) {
    int f = static_cast<int>(d / 1000);
    factor = f > 1 ? 1.0 - (f / 100.0) : 1.0;
    d *= factor;
    fullTime = d / speed; 
}
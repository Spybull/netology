#include "carpetPlane.h"

CarpetPlane::CarpetPlane(double s, std::string n) : Air(s, n) {}
CarpetPlane::CarpetPlane(double s) : Air(s, "Carpet plane") {}

void CarpetPlane::calcTime(double d) {
    if ( d < 5000 && d >= 1000)
        factor = 1 - (3.0 / 100);
    else if (d < 10000 && d >= 5000)
        factor = 1 - (10.0 / 100);
    else if (d >= 10000)
        factor = 1 - (5.0 / 100);
    else
        factor = 1;

    d *= factor;
    fullTime = d / speed;
}
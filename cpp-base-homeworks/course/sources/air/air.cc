#include "air.h"

Air::Air(double s, std::string n) : Transport(2, s, n) {
    fullTime = 0.0;
};

double Air::getfullTime() const {
    return fullTime;
};
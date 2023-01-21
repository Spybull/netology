#include "camelSpeed.h"

CamelSpeed::CamelSpeed(double s, double mt, std::string n) : Ground(s, mt, n) {}
CamelSpeed::CamelSpeed(double s, double mt) : Ground(s, mt, "Camel speed") {}

void CamelSpeed::calcTime(double d) {
    Ground::calcTime(d);
    stopCount -= 2;
    fullTime += 5 + 6.5 + stopCount * 8;
}
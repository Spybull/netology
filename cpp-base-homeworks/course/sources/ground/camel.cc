#include "camel.h"


Camel::Camel(double s, double mt, std::string n) : Ground(s, mt, n) {}
Camel::Camel(double s, double mt) : Ground(s, mt, "Camel") {}

void Camel::calcTime(double d)
{
    Ground::calcTime(d);
    --stopCount;
    fullTime += 5 + stopCount * 8;
}
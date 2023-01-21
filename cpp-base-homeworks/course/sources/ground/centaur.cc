#include "centaur.h"

Centaur::Centaur(double s, double mt, std::string n) : Ground(s, mt, n) {}
Centaur::Centaur(double s, double mt) : Ground(s, mt, "Centaur") {}

void Centaur::calcTime(double d) {
    Ground::calcTime(d);
    fullTime += stopCount * 2;
}

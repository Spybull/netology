#pragma once
#include "ground.h"

class Centaur : public Ground {
    public:
        Centaur(double s, double mt, std::string n);
        Centaur(double s, double mt);
        void calcTime(double d) override;
};
#pragma once
#include "ground.h"

class CamelSpeed : public Ground {
    public:
        CamelSpeed(double s, double mt, std::string n);
        CamelSpeed(double s, double mt);
        void calcTime(double d) override;
};
#pragma once
#include "air.h"

class CarpetPlane : public Air {
    public:
        CarpetPlane(double s, std::string n);
        CarpetPlane(double s);
        void calcTime(double d) override;
};
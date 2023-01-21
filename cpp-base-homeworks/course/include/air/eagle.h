#pragma once
#include "air.h"

class Eagle : public Air {
    public:
        Eagle(double s, std::string n);
        Eagle(double s);
        void calcTime(double d) override;
};
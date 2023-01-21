#pragma once
#include "ground.h"

class Camel : public Ground
{
    public:
        Camel(double s, double mt, std::string n);
        Camel(double s, double mt);
        void calcTime(double d) override;
};
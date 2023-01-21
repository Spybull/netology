#pragma once
#include "air.h"


class Broom : public Air {
    public:
        Broom(double s, std::string n);
        Broom(double s);
        void calcTime(double d) override;
};
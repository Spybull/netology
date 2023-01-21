#pragma once
#include "transport.h"

class Air : public Transport {
    protected:
        double factor;
        double fullTime;

        Air(double s, std::string n);

    public:
        void calcTime(double d) = 0;
        double getfullTime() const override;
};
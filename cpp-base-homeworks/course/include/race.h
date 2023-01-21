#pragma once
#include "transport.h"

enum {
    GROUND=1,
    AIR,
    GROUND_AND_AIR
};

enum {
    REG_DIFFERENT_TYPES,
    REG_REGISTERED,
    REG_NOT_REGISTERED
};

class Race
{
    protected:
        double distance;
        int type;

    public:
        Race(int t, double d);
        Race() = default;

        double getDistance();

        int regTransport(Transport *t);
        void unregAll(Transport *t);
        
        int getRegisteredCount(Transport *t);

        std::string getRegistered(Transport *t);
        std::string typeToString();

};
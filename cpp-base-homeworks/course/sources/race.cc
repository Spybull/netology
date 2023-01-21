#include "race.h"

Race::Race(int t, double d)
    : distance(d)
    , type(t)
{}

std::string Race::getRegistered(Transport *t) {
    
    Transport *tmp = t;
    std::string regNow = "";

    int c = 0;
    while (tmp != nullptr) {

        if (tmp->regStatus()) {
            regNow += !c ? tmp->name : ", " + tmp->name;
            ++c;
        }
        
        tmp = tmp->next;
    }

    return regNow;
}

int Race::regTransport(Transport *t) { 
    
    if (type != GROUND_AND_AIR)
        if (t->type != type)
            return REG_DIFFERENT_TYPES;

    if (t->regStatus())
        return REG_REGISTERED;

    t->reg();
    return REG_NOT_REGISTERED;
}

void Race::unregAll(Transport *t) {
    Transport *tmp = t;
    while (tmp != nullptr) {
        tmp->unreg();
        tmp = tmp->next;
    }
}

int Race::getRegisteredCount(Transport *t) {
    int count = 0;
    
    Transport *tmp = t;
    while(tmp != nullptr) {
        if (tmp->regStatus()) ++count;
        tmp = tmp->next;
    }
    return count;
}

double Race::getDistance() {
    return distance;
}

std::string Race::typeToString() {

    switch (type)
    {
        case GROUND:
            return "Racing for ground only transport.";
        break;

        case AIR:
            return "Racing for air only transport.";
        break;

        case GROUND_AND_AIR:
            return "Racing for ground and air transport.";
        break;
    }

    return "unknown type";
}
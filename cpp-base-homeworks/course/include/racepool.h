#pragma once

#include "transport.h"

class RacePool {
    private:
        int addedCount;
    public:
        Transport *head;
        RacePool();
        void addTransport(Transport *t);
        int getPoolSize() const;
        Transport *findMemberByName(std::string fname);
        Transport *findMemberById(int id);
};
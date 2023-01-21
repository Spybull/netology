#include "racepool.h"

RacePool::RacePool()
    : addedCount(0)
    , head(nullptr)
{}

void RacePool::addTransport(Transport *t) {
    int count = 1;
    ++addedCount;

    if (head == nullptr) {
        head = t;
        head->count = count;
        return;
    }

    Transport *tmp = head;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
        tmp->count = ++count;
    }

    tmp->next = t;
    tmp->next->count = ++count;
}

Transport *RacePool::findMemberByName(std::string fname) {
    Transport *tmp = head;
    while(tmp != nullptr) {
        if (tmp->name == fname)
            return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}

Transport *RacePool::findMemberById(int id) {
    Transport *tmp = head;
    while(tmp != nullptr) {
        if (tmp->count == id)
            return tmp;
        tmp = tmp->next;
    }
    return nullptr;
}

int RacePool::getPoolSize() const {
    return addedCount;
}
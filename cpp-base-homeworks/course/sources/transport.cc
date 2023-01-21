#include "transport.h"

Transport::Transport(int t, double s, std::string n)
: registration(false)
, speed(s)
, type(t)
, name(n)
, next(nullptr) {}

// Установить флаг регистрации
void Transport::reg() {
    this->registration = true;
}

// Сбросить флаг регистрации
void Transport::unreg() {
    this->registration = false;
}

// Получить флаг регистрации
bool Transport::regStatus() {
    return registration;
}
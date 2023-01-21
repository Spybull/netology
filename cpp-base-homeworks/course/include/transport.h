#pragma once
#include <string>

class Transport
{
    protected:
        bool registration;
        double speed;
        Transport(int t, double s, std::string n);
        Transport() = default;

    public:
        int type;
        int count;
        std::string name;
        Transport *next;

        // Установить флаг регистрации
        void reg();

        // Сбросить флаг регистрации
        void unreg();
        
        // Получить флаг регистрации
        bool regStatus();

        // Рассчитать время движения
        virtual void calcTime(double d) = 0;

        // Получить рассчитанное время движения
        virtual double getfullTime() const = 0;
};
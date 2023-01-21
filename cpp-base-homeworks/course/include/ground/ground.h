#pragma once
#include "transport.h"

class Ground : public Transport
{
    double moveTime; // Время движения без остановок
    double restDist; // Дистанция пройденная за время без остановок

    protected:
        double fullTime; // Итоговое время гонки
        int stopCount; // Количество сделанных остановок

        Ground(double s, double mt, std::string n);

    public:
        void calcTime(double d) override;
        double getfullTime() const override;
};
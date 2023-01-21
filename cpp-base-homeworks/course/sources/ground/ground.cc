#include "ground.h"

Ground::Ground(double s, double mt, std::string n)
: Transport(1, s, n) {
    moveTime = mt;
    fullTime = 0.0;
}

void Ground::calcTime(double d) {

    if (!d)    
        return;

    // Полный отрезок времени для всей дистанции
    fullTime = d / speed;

    // Количество остановок за всё время движения
    stopCount = fullTime / moveTime;

    // Расстояние пройденное за столько сколько можно отдыхать
    restDist = speed * moveTime;

    double res = d - restDist * stopCount;

    // Вычитаем одну остановку, если пришли в точку назначения без остатка
    if (res == 0)
        --stopCount;
}

double Ground::getfullTime() const {
    return fullTime;
}
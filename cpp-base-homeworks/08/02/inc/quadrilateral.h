#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include <iostream>
#include "figure.h"
#include "exceptions.h"

class Quadrilateral : public Figure {

    public:
        Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
        void printInfo() override;
        void getSides();
        void getAngles();
    protected:
        Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name);
        int sides[4];
        int angles[4];
};
#endif
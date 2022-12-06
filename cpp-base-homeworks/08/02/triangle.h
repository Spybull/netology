#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include "exceptions.h"

class Triangle : public Figure
{
    public:
        Triangle(int a, int b, int c, int A, int B, int C);
        virtual void printInfo() override;
        void getSides();
        void getAngles();

    protected:
        Triangle(int a, int b, int c, int A, int B, int C, std::string name);
        int sides[3];
        int angles[3];
};
#endif
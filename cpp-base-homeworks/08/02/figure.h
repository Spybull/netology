#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <stdexcept>

/// @brief exception indicating access out of the defined range
class sideCountZeroEx : public std::exception {

    public:
        
};

class Figure
{
    public:
        Figure();
        int getSidesCount();
        std::string getName();
        virtual void printInfo();

    protected:
        int sides_count;
        std::string name;
        Figure(int _sides_count, std::string _name);

};

#endif
#include <iostream>
#include <string>
#include "leaver.h"

int main()
{
    Leaver lv;
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << lv.leave(name) << std::endl;
    return 0;
}
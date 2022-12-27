#include <iostream>
#include <string>
#include "greeter.h"

int main()
{
    Greeter gt;
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << gt.greet(name) << std::endl;
    return 0;
}
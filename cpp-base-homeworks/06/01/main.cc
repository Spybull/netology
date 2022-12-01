#include <iostream>
#include "mathfunc.h"

int main()
{
    double num1, num2;
    int op;

    while (true)
    {
        std::cout << "Enter num1: ";
        std::cin >> num1;

        std::cout << "Enter num2: ";
        std::cin >> num2;

        op_label:
            std::cout << "Set operation (1 - add, 2 - sub, 3 - mul, 4 - div, 5 - pow): ";
            std::cin >> op;
            
            switch(op)
            {
                case ADD:
                    std::cout << num1 << " + " << num2 << " = " << add(num1, num2) << std::endl;
                break;

                case SUB:
                    std::cout << num1 << " - " << num2 << " = " << sub(num1, num2) << std::endl;
                break;

                case MUL:
                    std::cout << num1 << " * " << num2 << " = " << mul(num1, num2) << std::endl;
                break;

                case DIV:
                    try {
                        double res = div(num1, num2);
                        std::cout << num1 << " / " << num2 << " = " << res << std::endl;
                    } catch (const char *err) {
                        std::cerr << err << std::endl;
                    }
                break;

                case POW:
                    std::cout << num1 << " to the power of " << num2 << " = " << pow(num1, num2) << std::endl;
                break;

                default:
                    std::cout << "Ilegal input\n";
                    std::cin.clear();
                    std::cin.ignore(100500, '\n');

                    goto op_label;
                break;
            }
    }

    return 0;
}
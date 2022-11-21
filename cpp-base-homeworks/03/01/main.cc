#include <iostream>

class Calculator {

    double num1;
    double num2;

    public:
        bool set_num1(double);
        bool set_num2(double);
        double add()            { return num1 + num2; }
        double multiply()       { return num1 * num2; }
        double subtract_1_2()   { return num1 - num2; }
        double subtract_2_1()   { return num2 - num1; }
        double divide_1_2()     { return num1/num2; }
        double divide_2_1()     { return num2/num1; }
};

bool Calculator::set_num1(double num1) {
    if (num1 == 0) return false;
    this->num1 = num1;
    return true;
}

bool Calculator::set_num2(double num2) {
    if (num2 == 0) return false;
    this->num2 = num2;
    return true;
}

int main()
{
    double num1, num2;
    Calculator calc;

    while (true)
    {

        num1_label:
            std::cout << "Enter num1: ";
            std::cin >> num1;

            if (!calc.set_num1(num1)) {

                std::cout << "Ilegal input\n";

                std::cin.clear();
                std::cin.ignore(100500, '\n');

                goto num1_label;
            }

        num2_label:
            std::cout << "Enter num2: ";
            std::cin >> num2;

            if (!calc.set_num2(num2)) {

                std::cout << "Ilegal input\n";
                std::cin.clear();
                std::cin.ignore(100500, '\n');

                goto num2_label;
            }

        std::cout << "num1 + num2 = " << calc.add()          << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply()     << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2()   << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1()   << std::endl;
    }
    
    return 0;
}
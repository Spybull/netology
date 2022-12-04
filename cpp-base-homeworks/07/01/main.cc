#ifndef MODE
#error "Constant MODE wasn't defined!";
#endif

#include <iostream>

#if MODE == 1
    int add(int x, int y) {
        return x + y;
    }
#endif

int main()
{

#if MODE == 0
    std::cout << "Work on training mode\n";
#elif MODE == 1
    int n1, n2;
    std::cout << "Work on combat mode\n";
    
    std::cout << "Enter number 1: ";
    std::cin >> n1;

    std::cout << "Enter number 2: ";
    std::cin >> n2;

    std::cout << "Result: " << add(n1, n2) << std::endl;
#else
    std::cout << "Unknown mode!\n";
    return -1;
#endif

    return 0;
}
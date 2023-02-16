#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{   
    std::vector<int> v{4, 7, 9, 14, 12};
    
    std::cout << "Input values:\t";
    std::for_each(v.begin(), v.end(), [](const int &n) {
        std::cout << n << " ";
    });

    std::cout << "\nOutput values:\t";
    std::for_each(v.begin(), v.end(), [](const int &n) {
        std::cout << (n % 2? n*3 : n) << " ";
    });

    std::cout << std::endl;
    return 0;
}
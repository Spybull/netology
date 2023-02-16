#include <functional>
#include <iostream>
#include <cmath>
#include <algorithm>

constexpr double PI = 3.1415926;

int main(int argc, char const *argv[])
{
    std::vector<double> angles{30, 60, 90};

    std::cout << "[Input data]: ";
    std::for_each(angles.begin(), angles.end(), [angles](double &angle) {
        std::cout << angle << " * " << PI
                  << (angle == angles.back() ? " / 180 " : " / 180, ");
        angle *= PI / 180;
    });

    std::cout << "\n[Output data]:\n";

    std::vector<std::function<void(double)>> functions {
        [](double angle) { std::cout << "sin: " << sin(angle); },
        [](double angle) { std::cout << " cos: " << cos(angle); },
        [](double angle) { std::cout << " tan: " << tan(angle); }
    };

    for (const auto& angle : angles) {
        std::cout << angle << ": ";
            for (const auto& function : functions)
                function(angle);
        std::cout << std::endl;
    }

    return 0;
}
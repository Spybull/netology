#include <iostream>
#include <vector>
#include <variant>
#include <algorithm>
#include <ctime>
#include <any>

std::variant<int, std::string, std::vector<int>> get_variant()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
        case 0:
            result = 5;
            break;
        case 1:
            result = "string";
            break;
        case 2:
            result = std::vector<int>{ 1, 2, 3, 4, 5 };
            break;
        default:
            break;
	}
	return result;
}

int main(int argc, char const *argv[])
{
    auto val = get_variant();
    if (std::holds_alternative<int>(val))
        std::cout << std::get<int>(val) * 2;
    else if (std::holds_alternative<std::string>(val))
        std::cout << std::get<std::string>(val);
    else {
        auto v = std::get<std::vector<int>>(val);
        std::for_each(v.begin(), v.end(), [](int n){
            std::cout << n << " ";
        });
    }

    std::cout << std::endl;
    return 0;
}
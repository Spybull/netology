#include <iostream>
#include <vector>


template<typename T>
T power(T n) { return n * n; }

template<typename T>
void power(std::vector<T> &n) {
    for (auto &v : n) v *= v;
}

template<typename T>
void print(const std::vector<T> &n)
{
    for(auto it = n.begin(); it < n.end() - 1; ++it)
        std::cout << *it << ", ";
    std::cout << *(n.end() - 1) << std::endl;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    std::cout << "[IN]: " << n << std::endl;
    std::cout << "[OUT]: " << power(n) << std::endl;

    std::vector<int> v{-1, 4, 8};
    std::cout << "[IN]: ";

    print(v);
    power(v);

    std::cout << "[OUT]: ";
    print(v);

    return 0;
}
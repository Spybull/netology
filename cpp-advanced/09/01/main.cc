#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T> &dst, std::vector<T> &src) {
    dst = std::move(src);
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1{10,20,30,40,50},v2;

    move_vectors(v2, v1);

    for(const auto &n : v2)
        std::cout << n << std::endl;

    return 0;
}
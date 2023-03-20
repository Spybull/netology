#include <iostream>
#include <vector>
#include <set>

template<typename T>
void uniqme(std::vector<T> &v) {
    std::set<T> sTemp(v.begin(), v.end());
    v.assign(sTemp.begin(), sTemp.end());
}

template<typename T>
void print(const std::vector<T> &v) noexcept {
    for(const auto &i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1, 1, 2, 5, 6, 1, 2, 4};

    std::cout << "[IN]: ";
    print(v);

    uniqme(v);
    std::cout << "[OUT]: ";
    print(v);

    return 0;
}

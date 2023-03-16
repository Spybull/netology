#include <iostream>
#include <algorithm>
#include <vector>

class functor {
    
    int sum, count;
    public:
        functor(): sum(0), count(0) {};

    void operator()(int elem) {
        if ( ! (elem % 3) ) {
            sum += elem;
            ++count;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main(int argc, char const *argv[])
{

    std::vector<int> arr{4, 1, 3, 6, 25, 54};
    std::cout << "[IN]: ";
    for(const auto &n : arr)
        std::cout << n << " ";

    std::cout << std::endl;

    auto zf = std::for_each(arr.begin(), arr.end(), functor());
    std::cout << "[OUT]: get_sum() = "   << zf.get_sum()   << std::endl;
    std::cout << "[OUT]: get_count() = " << zf.get_count() << std::endl;
    return 0;
}
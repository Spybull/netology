#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <future>

const unsigned long MAX_CHUNK_SIZE = 2;

template<class Iterator, class UnaryFunction>
void foreach(Iterator first, Iterator last, UnaryFunction fx)
{
    unsigned long const len = std::distance(first, last);

    if (len <= MAX_CHUNK_SIZE)
    {
        for (; first != last; ++first)
            fx(*first);
    }
    else
    {
        Iterator mid_point = first;
        std::advance(mid_point, len / 2);
        std::future<void> first_half_res = std::async(std::launch::async,
                                                      foreach<Iterator, UnaryFunction>,
                                                      first,
                                                      mid_point,
                                                      fx);

        std::future<void> second_half_res = std::async(std::launch::async,
                                                       foreach<Iterator, UnaryFunction>,
                                                       mid_point,
                                                       last,
                                                       fx);
        first_half_res.wait();
        second_half_res.wait();
    }
}

int main()
{
    std::vector<int> v(10, 5);
    int x = 0;
    foreach(v.begin(), v.end(), [&x](int n){ x += n; });
    std::cout << x << std::endl;
    return 0;
}
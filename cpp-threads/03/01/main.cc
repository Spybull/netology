#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <random>
#include <algorithm>

template<typename T>
void min_idx(const T &v,
             int start_idx,
             std::promise<int> &&pr)
{
    auto m = start_idx;
    for(; start_idx < v.size(); ++start_idx)
        if ( v[start_idx] < v[m])
            m = start_idx;

    pr.set_value(m);
}

template<typename T>
void selectionSort(T &arr, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        std::promise<int> pr;
        std::future<int> ft_res = pr.get_future();
        std::future<void> task = std::async(std::launch::async, min_idx<T>, arr, i, std::move(pr));
        task.wait();
        auto midx = ft_res.get();
        std::swap(arr[i], arr[midx]);
    }
}

int main()
{
    std::vector v(10, 0);
    std::mt19937 gen(std::time(nullptr));
    std::uniform_int_distribution<int> dis(0, 10);
    auto rand_num([=]() mutable { return dis(gen); });
    std::generate(begin(v), end(v), rand_num);

    selectionSort(v, v.size());

    for(const auto &i : v)
        std::cout << i << " ";
        
    std::cout << std::endl;
    return 0;
}
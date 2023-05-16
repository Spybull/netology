#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>
#include <execution>
#include <ctime>
#include <map>
#include <iomanip>
#include <array>

#define MAX_THREADS 16

typedef std::vector<std::pair<std::vector<int>, std::vector<int>>> vpair_vv;

void sum(std::vector<int> &v1, std::vector<int> &v2) {
    
    for(size_t i = 0; i < v1.size(); ++i)
        if (v1[i] + v2[i] > std::numeric_limits<int>::max())
            std::cout << "Payload...\n";
}

int main()
{
    std::cout << "Number of hardware cores: "
              << std::thread::hardware_concurrency()
              << std::endl;

    std::mt19937 gen(std::time(nullptr));
    std::uniform_int_distribution<int> dis(0, 10000000);
    auto rand_num([=]() mutable { return dis(gen); });

    const int total_elements = 4;
    std::array<int, total_elements> el = {1000, 10000, 100000, 1000000};
    const int v_count = 2;

    for(const auto &i : el)
        std::cout << "\t\t" << i;
    std::cout << std::endl;

    for (int th_count = 1; th_count <= MAX_THREADS; th_count *= 2)
    {
        std::cout << th_count << " threads\t";

        for(int elem = 0; elem < total_elements; ++elem)
        {
            int elements = el[elem]/v_count;
            int base = static_cast<int>(elements / th_count);
            int rem = elements % th_count;

            vpair_vv vpairs;
            for (int i = 0; i < th_count; i++)
            {
                int sz = i < rem ? base + 1 : base;
                std::vector<int> v1(sz);
                std::vector<int> v2(sz);
                std::generate(std::execution::par, begin(v1), end(v1), rand_num);
                std::generate(std::execution::par, begin(v2), end(v2), rand_num);
                vpairs.push_back(std::make_pair(v1, v2));
            }

            std::vector<std::thread> threads;
            std::chrono::steady_clock::time_point start, end;
            for (auto &vectors_pairs : vpairs) {
                start = std::chrono::steady_clock::now();
                threads.push_back(std::thread(sum, std::ref(vectors_pairs.first), std::ref(vectors_pairs.second)));
            }

            for (auto &th: threads)
                th.join();

            end = std::chrono::steady_clock::now();
            auto diff = end - start;
            std::cout << std::fixed
                        << std::setprecision(7)
                        << std::chrono::duration<double, std::chrono::seconds::period>(diff).count()
                        << "s\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
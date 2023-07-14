#include <iostream>
#include "thread_pool.hh"


void f1() { std::cout << "f1 is running\n"; }
void f2() { std::cout << "f2 is running\n"; }

int main()
{
    std::size_t total_threads = std::thread::hardware_concurrency();
    thread_pool tp(total_threads);

    for(int i = 0; i < 5; ++i)
    {
        tp.submit(f1);
        tp.submit(f2);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    tp.stop_all();

    std::cout << "Completed!\n";
    std::cout << "Total threads: " << total_threads << std::endl;
    return 0;
}

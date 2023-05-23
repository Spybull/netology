#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

#define MEM_ORDER std::memory_order_relaxed
std::atomic<unsigned int> count{0};

void client(unsigned int max_clients)
{
    if (!max_clients)
        return;

    while (true)
    {
        count.fetch_add(1, MEM_ORDER);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Client " << count << std::endl;
        if (count.load(MEM_ORDER) == max_clients)
            return;
    }
}

void operational() {

    while(count.load(MEM_ORDER) > 0 ) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Exit client" << " " << std::endl;
        count.fetch_sub(1, MEM_ORDER);
    }
}

int main()
{
    std::thread client_thread(client, 5);
    std::thread operational_thread(operational);

    client_thread.join();
    operational_thread.join();

    std::cout << "Result clients: " << count << std::endl;
    return 0;
}
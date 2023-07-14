#pragma once
#include <vector>
#include <thread>
#include "safe_queue.hh"

class thread_pool
{
    private:
        std::vector<std::thread> workers;
        safe_queue<std::function<void()>> tasks;

    public:
        thread_pool(size_t threads);
        void submit(std::function<void()> fx);
        void stop_all();
        ~thread_pool();
};
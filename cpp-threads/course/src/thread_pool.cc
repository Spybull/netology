#include "thread_pool.hh"

thread_pool::thread_pool(size_t threads)
{
    for(size_t i = 0; i < threads; ++i)
    {
        workers.emplace_back([this] {
            while(true)
            {
                auto task = tasks.pop();
                if (!task) return;
                (*task)();
            }
        });
    }
}

void thread_pool::submit(std::function<void()> fx) {
    tasks.push(std::move(fx));
}

    void thread_pool::stop_all() {
        tasks.stop();
    }

thread_pool::~thread_pool()
{
    stop_all();
    for(std::thread &worker: workers)
        worker.join();
}
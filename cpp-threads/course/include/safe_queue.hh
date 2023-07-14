#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <optional>

template<typename T>
class safe_queue
{
    private:
        std::queue<T> data_queue;
        mutable std::mutex mtx;
        std::condition_variable cv;
        std::atomic<bool> done;

    public:
        safe_queue() : done(false) {}

        void push(T new_value)
        {
            std::lock_guard<std::mutex> lock(mtx);
            data_queue.push(std::move(new_value));
            cv.notify_one();
        }

        std::optional<T> pop()
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] {
                return done || !data_queue.empty();
            });

            if (data_queue.empty())
                return {};
            
            T value = std::move(data_queue.front());
            data_queue.pop();
            return value;
        }

        void stop()
        {
            done = true;
            cv.notify_all();
        }
};
#include <iostream>
#include <mutex>
#include <thread>

class Data
{
    int value;
    std::mutex mtx;
    public:
        Data(int value) : value(value) {}
        int get() const {
            return this->value;
        }
        void set(int newValue) {
            this->value = newValue;
        }
        std::mutex &getMutex() {
            return this->mtx;
        }
};

void swap_lock(Data &data1, Data &data2)
{
    if (&data1 == &data2)
        return;

    std::lock(data1.getMutex(), data2.getMutex());
    std::lock_guard lock1(data1.getMutex(), std::adopt_lock);
    std::lock_guard lock2(data2.getMutex(), std::adopt_lock);

    int temp = data1.get();
    data1.set(data2.get());
    data2.set(temp);
}

void swap_scoped(Data &data1, Data &data2)
{
    if (&data1 == &data2)
        return;

    std::scoped_lock grd(data1.getMutex(), data2.getMutex());

    int temp = data1.get();
    data1.set(data2.get());
    data2.set(temp);
}

void swap_uniq(Data &data1, Data &data2)
{
    if (&data1 == &data2)
        return;

    std::unique_lock<std::mutex> uniq1(data1.getMutex(), std::defer_lock);
    std::unique_lock<std::mutex> uniq2(data2.getMutex(), std::defer_lock);
    std::lock(uniq1, uniq2);

    int temp = data1.get();
    data1.set(data2.get());
    data2.set(temp);
}

int main(int argc, char const *argv[])
{
    Data data1(10);
    Data data2(20);

    std::thread t1([&]() {
        std::cout << "Swap with lock in thread 1" << std::endl;
        swap_lock(data1, data2);
    });

    std::thread t2([&]() {
        std::cout << "Swap with scoped_lock in thread 2" << std::endl;
        swap_scoped(data1, data2);
    });

    std::thread t3([&]() {
        std::cout << "Swap with unique_lock in thread 3" << std::endl;
        swap_uniq(data1, data2);
    });

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Data1 value: " << data1.get() << std::endl;
    std::cout << "Data2 value: " << data2.get() << std::endl;
    
    return 0;
}
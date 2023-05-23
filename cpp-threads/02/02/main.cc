#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <string_view>

#define PROGRESSBAR_PRECENT 10

enum {
    BUBBLE_SORT,
    SELECTION_SORT
};

std::mutex console_mutex;
std::condition_variable cv;
std::atomic<bool> all_done(false);

class ThreadInfo {
    static unsigned int threadCount;
    unsigned int uniqId;
    std::thread::id threadId;
    std::string threadProgress;
    std::vector<int> values;
    double execTime;
    size_t progress_interval;

    public:
        ThreadInfo(int calcSize)
        {
            std::lock_guard<std::mutex> lock(console_mutex);
            uniqId = ++threadCount;
            threadProgress.reserve(PROGRESSBAR_PRECENT);

            values.resize(calcSize);
            std::mt19937 gen(std::time(nullptr));
            std::uniform_int_distribution<int> dis(0, 100000);
            auto rand_num([=]() mutable { return dis(gen); });
            std::generate(begin(values), end(values), rand_num);
            progress_interval = values.size() / PROGRESSBAR_PRECENT;
        }

        unsigned int getThreadUniqId() { return uniqId; }
        std::thread::id getThreadId() { return threadId; }
        const std::string &getProgress() { return threadProgress; }
        double getExecTime() { return execTime; }

        void selectionSort()
        {
            size_t progress_counter = 0;
            auto start = std::chrono::steady_clock::now();
            int min = 0;
            for(size_t i = 0; i < values.size(); ++i)
            {
                min = i;
                for(size_t j = i + 1; j < values.size(); ++j)
                {
                    if (values[j] < values[min])
                        std::swap(values[j], values[min]);
                }
                progress_counter++;
                if (progress_counter >= progress_interval)
                {
                    ++(*this);
                    progress_counter = 0;
                    cv.notify_one();
                }
                auto end = std::chrono::steady_clock::now();
                execTime = std::chrono::duration<double>(end - start).count();
            }
        }

        void bubbleSort()
        {
            size_t progress_counter = 0;

            auto start = std::chrono::steady_clock::now();
            for (size_t idx_i = 0; idx_i + 1 < values.size(); ++idx_i)
            {
                for (size_t idx_j = 0; idx_j + 1 < values.size() - idx_i; ++idx_j)
                {
                    if (values[idx_j + 1] < values[idx_j])
                        std::swap(values[idx_j], values[idx_j + 1]);
                }

                progress_counter++;
                if (progress_counter >= progress_interval)
                {
                    ++(*this);
                    progress_counter = 0;
                    cv.notify_one();
                }
                auto end = std::chrono::steady_clock::now();
                execTime = std::chrono::duration<double>(end - start).count();
            }
        }

        ThreadInfo &operator++() {
            threadProgress += "|";
            return *this;
        }

        ThreadInfo operator++(int){
            ThreadInfo temp = *this;
            threadProgress += "|";
            return temp;
        }


        void operator()(int algo)
        {
            threadId = std::this_thread::get_id();
            switch (algo)
            {
                case BUBBLE_SORT:
                    bubbleSort();
                break;

                case SELECTION_SORT:
                    selectionSort();
                break;
                
                default: break;
            }
        }

};
unsigned int ThreadInfo::threadCount = 0;

void printThreadsProgress(std::vector<ThreadInfo> &data)
{
    while (!all_done)
    {
        std::unique_lock<std::mutex> lock(console_mutex);
        cv.wait(lock);

#ifdef _WIN32
        system("cls");
#elif __linux__
        system("clear");
#endif
        for(auto &info : data)
        {
            std::cout << "Thread № "        << info.getThreadUniqId()
                      << ";\tThread id: "   << info.getThreadId()
                      << ";\tProgress: "    << info.getProgress()
                      << ";\tExec time: "   << info.getExecTime();
            std::cout << std::endl;
        }
    }
}

int main()
{
    int threadsAvail = std::thread::hardware_concurrency();
    int inTh;

    std::cout << "Enter number of threads (total available "
              << threadsAvail << "): ";
    std::cin >> inTh;

    if (inTh <= 0)
    {
        std::cerr << "Can't run program with " << inTh
                  << " threads" << std::endl;
        return -1;
    }
    
    if (inTh > threadsAvail)
    {
        std::cerr << "Please don't enter more threads than available on host\n";
        return -2;
    }

    int calcType = 0;
    std::cout << "Enter type of calculation: \n";
    std::cout << "\t0: Bubble sort.\n"
                 "\t1: Selection sort\n";

    std::cout << "Enter: ";
    std::cin >> calcType;

    if (calcType < 0 || calcType > 1) {
        std::cout << "Error, calculation type not found\n";
        return -3;
    }

    int arraySize;
    std::cout << "Enter array size: ";
    std::cin >> arraySize;

    if (arraySize <= 0) {
        std::cout << "Very small array size. Abort\n";
        return 0;
    }

    std::vector<ThreadInfo> vthreadsInfo;
    std::vector<std::thread> threads;
    vthreadsInfo.reserve(inTh);
    threads.reserve(inTh);
    
    for(int i = 0; i < inTh; ++i)
    {
        vthreadsInfo.emplace_back(ThreadInfo(arraySize));
        threads.emplace_back(std::ref(vthreadsInfo.back()), calcType);
    }

    std::thread progressThread(printThreadsProgress, std::ref(vthreadsInfo));
    for(auto& thread : threads)
        if(thread.joinable())
            thread.join();

    all_done = true;
    cv.notify_one();

    progressThread.join();
    return 0;
}
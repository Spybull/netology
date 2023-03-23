#include <iostream>
#include <memory>

namespace my 
{
    template<typename T>
    class unique_ptr
    {
        private:
            T *uniq;

        public:
            unique_ptr(unique_ptr const &) = delete;
            unique_ptr &operator=(unique_ptr const &) = delete;
        
            unique_ptr(T *ptr) : uniq(ptr) {}

            T &operator*() {
                return *uniq;
            }

            T *release() noexcept
            {
                T *p = uniq;
                uniq = nullptr;
                return p;
            }

            ~unique_ptr() {
                if (uniq != nullptr)
                    delete uniq;
            }
    };
}


int main()
{
    // example
    int *ptr = new int;
    *ptr = 100;

    my::unique_ptr<int> p(ptr);

    std::cout << *p << std::endl;
    *p = 200;
    std::cout << *p << std::endl;
    
    int *raw = p.release();
    std::cout << *raw << std::endl;

    delete raw;
    return 0;
}


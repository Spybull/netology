#include <iostream>
#include <vector>
#include <cstdlib>
#include <exception>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <catch2/matchers/catch_matchers.hpp>

namespace mine
{
    enum VectorExitCodes {
        MEMORY_ALLOCATION_ERROR,
        SEG_FAULT,
        INDEX_OUT_OF_BOUD
    };

    class vectorException : public std::exception {
        private:
            int exCode;
        public:
            vectorException(int err_code) : exCode(err_code)
            {}

            virtual const char *what() const noexcept override {
                switch (exCode) {
                    case VectorExitCodes::MEMORY_ALLOCATION_ERROR:
                        return "Error! Memory allocation error!";
                    break;

                    case VectorExitCodes::INDEX_OUT_OF_BOUD:
                        return "Error! Index out of bound!";
                    break;

                    case VectorExitCodes::SEG_FAULT:
                        return "Error! Segmentation fault!";
                    break;

                    default:
                        break;
                }

                return "Unknown error";
            }
    };

    template <typename T>
    class vector
    {
        private:
            T *basic_array;
            size_t cap, ratio;
            size_t total_size;

            T *safe_malloc(size_t nsz) {
                T *tmp = static_cast<T*>(malloc(sizeof(T) * nsz));
                if ( tmp == nullptr )
                    throw vectorException(VectorExitCodes::MEMORY_ALLOCATION_ERROR);

                return tmp;
            }
            T *safe_calloc(size_t nsz, size_t n=1) {
                T *tmp = static_cast<T*>(calloc(nsz, sizeof(T) * n));
                if ( tmp == nullptr )
                    throw vectorException(VectorExitCodes::MEMORY_ALLOCATION_ERROR);
                
                return tmp;
            }
            T *safe_realloc(T *src_ptr, size_t nsz) {
                if ( src_ptr == nullptr )
                    throw vectorException(VectorExitCodes::SEG_FAULT);

                T *tmp = static_cast<T*>(realloc(src_ptr, sizeof(T) * nsz));
                if ( tmp == nullptr )
                    throw vectorException(VectorExitCodes::MEMORY_ALLOCATION_ERROR);

                return tmp;
            }

        public:
            vector()
            : cap(0)
            , ratio(2)
            , total_size(0)
            , basic_array(nullptr)
            {}

            vector(size_t n) : vector() {
                basic_array = safe_calloc(n);
                total_size = cap = n;
            }

            vector(const vector &src) {
                total_size = src.total_size;
                ratio = src.ratio;
                cap = src.cap;

                basic_array = safe_malloc(cap);

                for(size_t i = 0; i < total_size; ++i)
                    basic_array[i] = src.basic_array[i];
            }

            inline size_t size() const noexcept {
                return total_size;
            }

            inline size_t capacity() const noexcept {
                return cap;
            }

            void push_back(const T &value)
            {
                if ( !cap )
                {
                    cap = 1;
                    basic_array = safe_calloc(cap);
                }
                else if ( cap <= total_size )
                {
                    cap *= ratio;
                    basic_array = safe_realloc(basic_array, cap);
                }
                
                basic_array[total_size++] = value;
            }

            void pop_back() {
                if ( cap == 0 || total_size == 0 )
                    throw vectorException(VectorExitCodes::SEG_FAULT);
                
                --total_size;
                int i = 1;

                for(; i < total_size; i *= ratio);
                cap = i;

                basic_array[total_size] = 0;
            }

            T &at(size_t index) const {

                if (index > total_size || index == total_size)
                    throw vectorException(VectorExitCodes::INDEX_OUT_OF_BOUD);

                return basic_array[index];
            }

            vector &operator=(vector &src)
            {
                if (basic_array == src.basic_array)
                    return *this;

                if ( cap > src.cap || cap < src.cap ) {
                    free(basic_array);
                    basic_array = safe_malloc(src.cap);
                }

                for(size_t i = 0; i < src.total_size; ++i)
                    basic_array[i] = src.basic_array[i];

                cap = src.cap;
                ratio = src.ratio;
                total_size = src.total_size;

                return *this;
            }

            T &operator[](size_t &index) const {
                return basic_array[index];
            }

            T &operator[](size_t &index) {
                return basic_array[index];
            }
            
            T *cbegin() const { return basic_array; }
            T *cend() const { return basic_array + total_size; }

            T *begin() { return basic_array; }
            T *end() { return basic_array + total_size; }

            ~vector() {
                if ( basic_array != nullptr)
                    free(basic_array);
            }
    };
}


int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}

TEST_CASE("diff std::vector with mine::vector", "[vector]") {

    GIVEN( "An two empty vectors" ) {
        auto std_vector = std::vector<int>{};
        auto my_vector = mine::vector<int>{};

        THEN( "The size and capacity are equal and starts at 0" ) {
            REQUIRE(std_vector.size() == 0);
            REQUIRE(my_vector.size() == 0);

            REQUIRE(std_vector.size() == my_vector.size());
            REQUIRE(std_vector.capacity() == my_vector.capacity());
        }

        WHEN( "Method push_back() works as expected" ) {
            std_vector.push_back(100);
            my_vector.push_back(100);

            THEN( "The sizes and capacities changed" ) {
                REQUIRE(std_vector.size() == my_vector.size());
                REQUIRE(std_vector.capacity() == my_vector.capacity());
            }
        }

        WHEN( "Method 'at()' works as expected" ) {
            std_vector.push_back(0);
            my_vector.push_back(0);

            std_vector.at(0) = 0xFFFC;
            my_vector.at(0) = 0xFFFC;

            THEN( "The values were changed" ) {
                REQUIRE(std_vector.at(0) == 0xFFFC);
                REQUIRE(my_vector.at(0) == 0xFFFC);
                REQUIRE(std_vector.at(0) == my_vector.at(0));
            }
        }
    }

    GIVEN( "Two vectors with predefined sizes" ) {
        std::vector<int> std_vector(1000);
        mine::vector<int> my_vector(1000);

        THEN( "The size and capacity are equal and starts at 1000" ) {
            REQUIRE(std_vector.size() == 1000);
            REQUIRE(my_vector.size() == 1000);

            REQUIRE(std_vector.size() == my_vector.size());
            REQUIRE(std_vector.capacity() == my_vector.capacity());
        }

        WHEN( "push_back() some elements" ) {
            std_vector.push_back(300);
            my_vector.push_back(100);

            THEN( "Capacity must be equal" ) {
                REQUIRE(std_vector.capacity() == my_vector.capacity());
            }
        }
    }
}

TEST_CASE( "Check copy operator" )
{
    mine::vector<int> my_vector1;
    const int sz = 5;
    for (int i = 1; i <= sz; ++i)
        my_vector1.push_back(10 * i);

    mine::vector<int> my_vector2;
    my_vector2 = my_vector1;

    REQUIRE(my_vector1.size() == my_vector2.size());
    REQUIRE(my_vector1.capacity() == my_vector2.capacity());

    for (int i = 0; i < sz; ++i)
        REQUIRE(my_vector1.at(i) == my_vector2.at(i));
}

TEST_CASE( "Check copy constructor" ) {
    mine::vector<int> v1(100);
    mine::vector<int> v2(v1);

    REQUIRE(v1.size() == v2.size());
    REQUIRE(v1.capacity() == v2.capacity());

    v2.push_back(100);
    REQUIRE(v1.size() != v2.size());
    REQUIRE(v1.capacity() != v2.capacity());

}

TEST_CASE( "Check pop_back() method" ) {
    mine::vector<int> v1;
    CHECK_THROWS_WITH(v1.pop_back(), "Error! Segmentation fault!");
}

TEST_CASE( "Check begin() and end() methods" ) {
    mine::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);

    REQUIRE(v1.at(0) == *v1.begin());
    REQUIRE(v1.at(1) == *(v1.end() - 1));
}
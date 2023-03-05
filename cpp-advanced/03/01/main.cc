#include <iostream>
#include <new>

class smart_array {

    int size, *ptr, count;

    public:
        smart_array(int size)
        : size(size)
        , ptr(new int[size]())
        , count(0)
        {}

        void add_element(int elem) {
            if ( count == size )
                throw std::bad_alloc();

            ptr[count++] = elem;
        }

        int get_element(int elem) const {
            if ( elem > (size - 1) || elem < 0 )
                throw std::range_error("Out of range");

            return ptr[elem];
        }

        int operator[](int elem) const {            
            return get_element(elem);
        }

        ~smart_array() {
            delete []ptr;
        }
};

int main(int argc, char const *argv[])
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
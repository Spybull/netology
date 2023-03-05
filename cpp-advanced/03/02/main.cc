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

        void operator=(smart_array &newArr) {

            delete []this->ptr;
            this->size = newArr.size;
            this->count = 0;

            this->ptr = new int[newArr.size];
            std::copy(newArr.ptr, newArr.ptr + newArr.size, this->ptr);
        }

        void print() const {
            for(int i = 0; i < size; ++i)
                std::cout << ptr[i] << " ";
            std::cout << std::endl;
        }

        ~smart_array() {
            delete []ptr;
        }
};

int main(int argc, char const *argv[])
{
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44); 
    new_array.add_element(34);

    std::cout << "Before: "; arr.print();
    arr = new_array;
    std::cout << "After: "; arr.print();

    return 0;
}
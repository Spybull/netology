#include <iostream>

class smart_array
{
    int size, count, *ptr;

    public:

        smart_array(int size): size(size), count(0) {
            if (size <= 0)
                throw std::bad_alloc();

            ptr = new int[size]();

            if (ptr == nullptr)
                throw std::bad_alloc();
        }

        smart_array(const smart_array &newArr) {

            size = newArr.size;
            count = newArr.count;
            ptr = new int[size];

            for (int i = 0; i < count; ++i)
                ptr[i] = newArr[i];
        }

        void add_element(int elem) {
            if ( count == size )
                throw std::bad_alloc();

            ptr[count++] = elem;
        }

        int get_element(int elem) const {
            if ( elem >= size || elem < 0 )
                throw std::range_error("Out of range");

            return ptr[elem];
        }

        int operator[](int elem) const {            
            return get_element(elem);
        }

        smart_array &operator=(smart_array &newArr) {

            if (ptr == newArr.ptr)
                return *this;

            delete []ptr;
            size = newArr.size;
            count = newArr.count;
            ptr = new int[size];
            
            for(int i = 0; i < count; ++i)
                ptr[i] = newArr[i];

            return *this;
        }

        void print() const {
            for(int i = 0; i < count; ++i)
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


    std::cout << "Before: ";
    arr.print();

    arr = new_array;
    
    std::cout << "After: ";
    arr.print();

    return 0;
}
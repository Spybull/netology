#include <iostream>

template <typename T>
class table {

    T **ptr;
    int row, col;

    public:
        table(int row, int col) : row(row), col(col) {

            ptr = new T*[row];
            for(int i = 0; i < row; ++i)
                ptr[i] = new T[col];
        }

        T *operator[](int pos) const {
            return ptr[pos];
        }

        T *operator[](int pos) {
            return ptr[pos];
        }

        int Size() const {
            return row * col;
        }

        ~table()
        {
            for(int i = 0; i < row; ++i)
                delete []ptr[i];
            delete []ptr;
        }

};


int main(int argc, char const *argv[])
{
    auto test1 = table<char>(2, 3);
    test1[0][1] = 'w';
    std::cout << "Regular result: " << test1[0][1] << std::endl;
    std::cout << "Table size: " << test1.Size() << std::endl;

    std::cout << std::endl;

    const auto test2 = table<int>(2, 3);
    test2[0][1] = 4;
    std::cout << "Const result: " << test2[0][1] << std::endl;
    std::cout << "Table size: " << test2.Size() << std::endl;

    return 0;
}
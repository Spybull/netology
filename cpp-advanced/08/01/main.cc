#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    // clone()
    std::unique_ptr<tridiagonal_matrix> clone() {

        auto ptr = std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
        if (!ptr)
            throw std::bad_alloc();

        return ptr;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(down, upper, middle);

    if (!matrix) {
        std::cerr << "Error creating unique ptr!\n";
        return -1;
    }

    try {
        auto matrix_clone = matrix->clone();
    } catch(std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    
    return 0;
}
 
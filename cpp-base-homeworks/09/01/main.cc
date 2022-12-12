#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

    inline double div() const {
        return static_cast<double>(numerator_)/denominator_;
    }

public:
	Fraction(int numerator, int denominator) {

        if (denominator == 0)
            throw std::runtime_error("Division by zero");

		numerator_ = numerator;
		denominator_ = denominator;
	}

    /* == and != */
    bool operator==(Fraction fRight) {
        return div() == fRight.div() ? true : false;
    }
    bool operator!=(Fraction fRight) {
        return !(*this == fRight);
    }

    /* > and < */
    bool operator>(Fraction fRight) {
        return div() > fRight.div() ? true : false;
    }
    bool operator<(Fraction fRight)  {
        return fRight > *this ? true : false;
    }

    // <= and  >=
    bool operator<=(Fraction fRight) {
        return !(*this > fRight);
    }
    bool operator>=(Fraction fRight) {
        return !(*this < fRight);
    }
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
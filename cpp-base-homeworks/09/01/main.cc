#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

   inline int nod(int d1, int d2) {
        int r = 0;
        while(d2 > 0) {
            r = d1 % d2;
            d1 = d2;
            d2 = r;
        }
        return d1;
    }

    inline void reduce(int &n, int &d) {
        int r = nod(abs(n), d);
        n /= r;
        d /= r;
    }

public:
	Fraction(int numerator, int denominator) {

        if (denominator == 0)
            throw std::runtime_error("Division by zero");

        reduce(numerator, denominator);
		numerator_ = numerator;
		denominator_ = denominator;

	}

    /* == and != */
    bool operator==(Fraction fRight) {
        if (denominator_ == fRight.denominator_)
            return (numerator_ == fRight.numerator_);

        return false;
    }

    bool operator!=(Fraction fRight) {
        return !(*this == fRight);
    }

    // /* > and < */
    bool operator>(Fraction fRight) {

        if (denominator_ == fRight.denominator_)
            return (numerator_ > fRight.numerator_);
        else if (numerator_ == fRight.numerator_)
            return (denominator_ < fRight.denominator_);
        else {
            int n1 = numerator_ * fRight.denominator_;
            int n2 = fRight.numerator_ * denominator_;
            return (n1 > n2);
        }

    }
    bool operator<(Fraction fRight)  {
        return (fRight > *this);
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

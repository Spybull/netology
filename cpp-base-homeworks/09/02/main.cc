#include <iostream>
#include <exception>

class Fraction
{
private:
	int numerator_;
	int denominator_;

   int nod(int d1, int d2) {
        int r = 0;
        while(d2 > 0) {
            r = d1 % d2;
            d1 = d2;
            d2 = r;
        }
        return d1;
    }

    void reduce(int &n, int &d) {
        int r = nod(abs(n), d);
        n /= r;
        d /= r;
    }

public:
    const std::string toString() const {
        return std::to_string(numerator_) + "/" + std::to_string(denominator_);
    }

	Fraction(int numerator, int denominator) {

        if (denominator == 0)
            throw std::runtime_error("Division by zero");

		numerator_ = numerator;
		denominator_ = denominator ;
	}

    /* == and != */
    bool operator==(Fraction fRight) {
        reduce(numerator_, denominator_);
        reduce(fRight.numerator_, fRight.denominator_);

        if (denominator_ == fRight.denominator_)
            return (numerator_ == fRight.numerator_);

        return false;
    }
    bool operator!=(Fraction fRight) {
        return !(*this == fRight);
    }

    // /* > and < */
    bool operator>(Fraction fRight) {

        reduce(numerator_, denominator_);
        reduce(fRight.numerator_, fRight.denominator_);

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

    Fraction operator+(const Fraction &fRight) {

        int f1 = 0, f2 = 0;
        if (denominator_ == fRight.denominator_) {
            f1 = numerator_ + fRight.numerator_;
            f2 = denominator_;
        } else {
            f1 = numerator_ * fRight.denominator_ + fRight.numerator_ * denominator_;
            f2 = denominator_ * fRight.denominator_;
        }

        reduce(f1, f2);
        return Fraction(f1, f2);
    }

    Fraction operator-(const Fraction &fRight) {

        int f1 = 0, f2 = 0;
        if (denominator_ == fRight.denominator_) {
            f1 = numerator_ - fRight.numerator_;
            f2 = denominator_;
        } else {
            f1 = numerator_ * fRight.denominator_ - fRight.numerator_ * denominator_;
            f2 = denominator_ * fRight.denominator_;
        }
        reduce(f1, f2);
        return Fraction(f1, f2);
    }

    Fraction operator*(const Fraction &fRight) {
        int f1 = numerator_ * fRight.numerator_;
        int f2 = denominator_ * fRight.denominator_;
        reduce(f1, f2);
        return Fraction(f1, f2);
    }

    Fraction operator/(const Fraction &fRight) {
        return *this * Fraction(fRight.denominator_, fRight.numerator_);
    }

    Fraction& operator++() {
        numerator_ += denominator_;
        reduce(numerator_, denominator_);
        return *this;
    }
    Fraction& operator--() {
        numerator_ -= denominator_;
        reduce(numerator_, denominator_);
        return *this;
    }

    Fraction operator++(int) {
        Fraction tmp = *this;
        numerator_ += denominator_;
        reduce(numerator_, denominator_);
        return tmp;
    }

    Fraction operator--(int) {
        Fraction tmp = *this;
        numerator_ -= denominator_;
        reduce(numerator_, denominator_);
        return tmp;
    }
};

void userInput(int &input, const char *msg)
{      
    while (true) {
        std::cout << msg;
        if ( !(std::cin >> input ) || std::cin.get()!='\n' ) {
            std::cout << "Error init value must contain only numbers!\n";
            std::cin.clear();
            std::cin.ignore(100500, '\n');
        } else {
            break;
        }
    }
}

int main()
{
    int enumerator_, denominator_;

    userInput(enumerator_, "Enter enumerator 1: ");

    while (true) {
        userInput(denominator_, "Enter denominator 1: ");
        if (denominator_ == 0)
            std::cout << "Division by zero, retype denominator\n";
        else
            break;
    }

    Fraction f1(enumerator_, denominator_);

    userInput(enumerator_, "Enter enumerator 2: ");

    while (true) {
        userInput(denominator_, "Enter denominator 2: ");
        if (denominator_ == 0)
            std::cout << "Division by zero, retype denominator\n";
        else
            break;
    }

    Fraction f2(enumerator_, denominator_);

    std::cout << f1.toString() << " + "
              << f2.toString() << " = "
              << (f1 + f2).toString() << std::endl;

    std::cout << f1.toString() << " - "
              << f2.toString() << " = "
              << (f1 - f2).toString() << std::endl;

    std::cout << f1.toString() << " * "
              << f2.toString() << " = "
              << (f1 * f2).toString() << std::endl;

    std::cout << f1.toString() << " / "
              << f2.toString() << " = "
              << (f1 / f2).toString() << std::endl;

    std::cout << "++" << f1.toString() << " * "
              << f2.toString() << " = "
              << (++f1 * f2).toString() << std::endl;

    std::cout << "Value of 1 fraction is: "
              << f1.toString() << std::endl;
    
    
    std::cout << f1.toString() << "--"
              << " * " << f2.toString()
              << " = " << (f1-- * f2).toString()
              << std::endl;

    std::cout << "Value of 1 fraction is: "
              << f1.toString() << std::endl;

	return 0;
}

#include <iostream>
#include <string>

class big_integer {
    private:
        std::string str;
        bool isOverFlow;
        bool isNegative;
        int integerNumber;
    public:

        big_integer()
        : str("0")
        , isOverFlow(false)
        , isNegative(false)
        , integerNumber(0) {}

        big_integer(std::string s) : big_integer()
        {
            if ( s.length() )
                str = s;

            // safety for ----NUMBER
            size_t mx = str.find_first_not_of('-');
            if ( mx % 2 )
                isNegative = true;

            int check = std::atoi(str.substr(mx).c_str());

            if ( check < 0 )
                isOverFlow = true;
            else
                integerNumber = check;
        }

        big_integer(const big_integer &s) = default;
        big_integer &operator=(const big_integer &s) = default;

        big_integer(big_integer &&s) {
            str = std::move(s.str);

            isOverFlow = s.isOverFlow;
            s.isOverFlow = false;

            isNegative = s.isNegative;
            s.isNegative = false;

            integerNumber = s.integerNumber;
            s.integerNumber = 0;
        }

        big_integer &operator=(big_integer &&s) {

            if (&s == this)
                return *this;
            
            str = std::move(s.str);

            isOverFlow = s.isOverFlow;
            s.isOverFlow = false;

            isNegative = s.isNegative;
            s.isNegative = false;

            integerNumber = s.integerNumber;
            s.integerNumber = 0;

            return *this;
        }

        big_integer operator=(const std::string &s) {
            return (*this = std::move(big_integer(s)));
        }

        int isOvfOperation(const big_integer &s2, const char op) const noexcept {

            int checkOvf = 0;
            if (!isOverFlow && !s2.isOverFlow)
            {
                switch(op)
                {
                    case '+':
                        checkOvf = integerNumber + s2.integerNumber;
                    break;

                    case '*':
                        checkOvf = integerNumber * s2.integerNumber;
                    break;

                    default:
                        break;
                }
            }

            return checkOvf;
        }

        big_integer operator+(big_integer &s2)
        {
            if ( int checkOvf; checkOvf = isOvfOperation(s2, '+') >=  0 )
            {
                if ( isNegative && s2.isNegative )
                    integerNumber = -checkOvf;
                else if ( isNegative )
                    integerNumber = s2.integerNumber - integerNumber;
                else if ( s2.isNegative )
                    integerNumber -= s2.integerNumber;
                else
                    integerNumber += s2.integerNumber;

                return std::move(big_integer(std::to_string(integerNumber)));
            }

            std::string::reverse_iterator f_begin(str.rbegin()), f_end(str.rend()),
                                          s_begin(s2.str.rbegin()), s_end(s2.str.rend());

            if (str.length() < s2.str.length()) {
                std::swap(f_begin, s_begin);
                std::swap(f_end, s_end);
            }

            int n1, n2, next, sum;
            sum = next = n1 = n2 = 0;
            std::string result;
            for (;f_begin != f_end; ++f_begin)
            {
                n1 = static_cast<int>(*f_begin - '0');
                n2 = 0;

                if (s_begin != s_end) {
                    n2 = *s_begin - '0';
                    s_begin++;
                }

                sum = n1 + n2 + next;
                if ( sum >= 10 ) {
                    next = static_cast<int>(sum / 10);
                    sum %= 10;
                } else 
                    next = 0;

                result.insert(0, std::to_string(sum));
            }

            if ( next > 0 )
                result.insert(0, std::to_string(next));

            return std::move(big_integer(result));
        }

        big_integer operator*(int num) noexcept
        {
            big_integer s2(std::to_string(num));
            std::string result;

            if ( int checkOvf(isOvfOperation(s2, '*')); checkOvf >  0)
            {
                s2.integerNumber = isNegative || s2.isNegative? -checkOvf : checkOvf;
                s2.str = std::to_string(s2.integerNumber);
                return std::move(s2);
            }

            std::string::reverse_iterator f_begin(str.rbegin()), f_end(str.rend()),
                                          s_begin(s2.str.rbegin()), s_end(s2.str.rend());

            if (str.length() > s2.str.length()) {
                std::swap(f_begin, s_begin);
                std::swap(f_end, s_end);
            }

            int n1, n2, next, mul;
            mul = next = n1 = n2 = 0;

            for (;f_begin != f_end; ++f_begin)
            {
                n1 = static_cast<int>(*f_begin - '0');
                if (n1 == 0) {
                    result.insert(0, "0");
                    continue;
                }

                for(;s_begin != s_end; ++s_begin)
                {
                    n2 =  static_cast<int>(*s_begin - '0');
                    mul = n1 * n2 + next;

                    if ( mul >= 10 ) {
                        next = static_cast<int>(mul / 10);
                        mul %= 10;
                    } else
                        next = 0;

                    result.insert(0, std::to_string(mul));
                }
            }

            if ( next > 0 )
                result.insert(0, std::to_string(next));

            return std::move(big_integer(result));
        }

        friend std::ostream& operator<<(std::ostream& os, const big_integer& s);
};

std::ostream& operator<<(std::ostream& os, const big_integer& s)
{
    os << s.str;
    return os;
}

int main()
{
    auto number1 = big_integer("4");
    auto number2 = big_integer("1");
    
    std::cout << "number1: " << number1 << std::endl;
    std::cout << "number2: " << number2 << std::endl;

    auto result = number1 + number2;
    std::cout << number1 << " + " << number2 << " = " << result << std::endl;

    int multiplier = -10;
    auto result2 = result * multiplier;
    std::cout << result << " * " << multiplier << " = " << result2 << std::endl;
    std::cout << "--------------------------------------\n" << std::endl;

    //Overflow example...
    number1 = "2147483647";
    number2 = "1000000000";

    std::cout << "number1: " << number1 << std::endl;
    std::cout << "number2: " << number2 << std::endl;

    result = number1 + number2;
    std::cout << number1 << " + " << number2 << " = " << result << std::endl;

    multiplier = 5;
    result2 = result * multiplier;
    std::cout << result << " * " << multiplier << " = " << result2 << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    return 0;
}
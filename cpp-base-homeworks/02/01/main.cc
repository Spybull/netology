#include <iostream>
#include <limits>

enum class Months
{
    JAN = 1,  FEB,
    MAR, APR, MAY,
    JUN, JUL, AUG,
    SEP, OCT, NOV,
    DEC
};

int main()
{
    const std::string months[] =
    {   "", "January", "February",
        "March", "April", "May",
        "June", "July", "August",
        "September", "October", "November",
        "December"
    };   
    
    int input = 0;
    while(true)
    {
        std::cout << "Enter number of months: ";
        std::cin>>input;

        if ( std::cin.fail() ) {
            std::cout << "Pass only numbers!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::digits10, '\n');
            continue;
        }

        if (input == 0) {
            std::cout << "Bye bye\n";
            break;
        }

        if (input < 0 || input > 12) {
            std::cout << "Only allowed numbers between 1-12\n";
            continue;
        }

        Months month = static_cast<Months>(input);
        std::cout << months[static_cast<int>(month)] << std::endl;
    }

    return 0;
}
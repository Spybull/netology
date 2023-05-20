#include "parser.hh"
#include <clocale>

#ifdef _WIN32
#include <windows.h>
#endif


int main()
{
#ifdef _WIN32 
    std::setlocale(LC_ALL, "ru_RU.utf8");
#endif

    try {
        ini_parser::Parser parser("test.ini");
        std::cout << parser.get_value<int>("Section1.var4") << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

#ifdef _WIN32
    system("pause");
#endif

    return 0;
}
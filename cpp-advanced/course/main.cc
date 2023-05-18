#include "parser.hh"
#include <clocale>

int main()
{
#ifdef _WIN32
    #include <windows.h>
    std::setlocale(LC_ALL, "ru_RU.utf8");
#endif

    try
    {
        ini_parser::Parser parser("tests/mistakes03.ini");
        std::cout << parser.get_value<std::string>("other.favorite_quote") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: \n"
                  << "\t" << e.what()
                  << std::endl;
    }

    return 0;
}
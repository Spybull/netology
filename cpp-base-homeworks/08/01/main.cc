#include <iostream>

int function(std::string str, int forbidden_length)
{
    int len = static_cast<int>(str.length());

    if ( forbidden_length == len )
        throw std::runtime_error("bad_length");

    return len;
}

int main()
{
    int len;

    while (true)
    {
        std::cout << "Enter forbidden length: ";

        if (std::cin >> len)
        {
            if (len <= 0)
                std::cout << "Error length cannot be <=0\n";
            else
                break;
        }
        else
        {
            std::cout << "Error input must contain only numbers!\n";
        }
        
        std::cin.clear();
        std::cin.ignore(100500, '\n');
    }

    std::string word;
    while(true)
    {
        std::cout << "Enter a word: ";
        std::cin >> word;

        try {
            size_t wordLen = function(word, len);

            std::cout << "Length of word " << word << " is "
                      << wordLen << std::endl;

        } catch(std::exception &ex) {

            std::cout << "[" << ex.what() << "] ";
            std::cout << "You've entered a word of forbidden length! Bye-Bye"
                      << std::endl;
            return -1;
        }
    }

    return 0;
}
#include <iostream>

class Counter {

    int count;

    public:
        Counter() : count(1) {}
        Counter(int count) { this->count = count; }

        int get();
        int inc();
        int dec();
};

int Counter::get() { return this->count; }
int Counter::inc() { return this->count++; }
int Counter::dec() { return this->count--; }

int main()
{
    Counter *count;

    int init = 0;
    char yn;

    std::cout << "Do you want to setup init value? y/n: ";
label:
    std::cin >> yn;

    if (yn == 'y')
    {
        while(true) {
            std::cout << "Enter init value: ";
            if (std::cin >> init) {
                break;
            } else {
                std::cout << "Error init value must contain only numbers!\n";
                std::cin.clear();
                std::cin.ignore(100500, '\n');
            }
        }

        count = new Counter(init);
    }
    else if (yn == 'n') {
        count = new Counter();
    }
    else
    {
        std::cin.clear();
        
        std::cout << "Please type y or n: ";
        goto label;
    }

    char comm;
    while (true)
    {
        std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
        std::cin >> comm;

        if (comm == 'x') {
            std::cout << "Bye bye\n";
            break;
        }

        switch (comm)
        {
            case '+': count->inc(); break;
            case '-': count->dec(); break;

            case '=': 
                std::cout << count->get() << std::endl;
            break;

            default:
                std::cout << "Whoops, you must enter only ('+', '-', '=' or 'x')\n";
                std::cin.clear();
                std::cin.ignore(100500, '\n');
            break;
        }
    }

    delete count;
    return 0;
}
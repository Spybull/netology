#include <iostream>

struct Credit {
    std::string name;
    float balance;
    int num;
};

template <class Y> void ReadInput(const char *msg, Y &input) {

    while(true)
    {
        std::cout << msg;
        if (std::cin >> input)
        {
            break;
        }
        else
        {
            std::cout << "Error input must contain only numbers!\n";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
    }
}

void PrintInfo(const Credit *credit) {
    std::cout << credit->name << " "
              << credit->num  << " "
              << credit->balance << "\n";
}

int main()
{
    Credit *credit = new Credit;
    float newBalance = 0;

    ReadInput("Введите номер счёта: ", credit->num);

    while(credit->name.empty()) {
        std::getline(std::cin, credit->name);
        if (credit->name.empty()) {
            std::cout << "Введите имя владельца: ";
            continue;
        }
    }

    ReadInput("Введите баланс: ", credit->balance);
    ReadInput("Введите новый баланс: ", newBalance);

    credit->balance += newBalance;
    PrintInfo(credit);

    delete credit;
    return 0;
}
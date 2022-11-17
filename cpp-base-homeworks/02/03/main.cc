#include <iostream>

struct Address {
    std::string city;
    std::string street;
    unsigned int homeNum;
    unsigned int flat;
    unsigned int index;
};

void print(const Address &addr) {
    std::cout << "Город: "         << addr.city     << std::endl
              << "Улица: "         << addr.street   << std::endl
              << "Номер дома: "    << addr.homeNum  << std::endl
              << "Номер квартиры:" << addr.flat     << std::endl
              << "Индекс: "        << addr.index    << std::endl
              << std::endl;
}

int main()
{
    Address addr1 = {"Moscow", "Arbat", 12, 8, 123456};
    print(addr1);

    Address addr2;
    addr2.city = "Izhevsk";
    addr2.street = "Pushkina";
    addr2.homeNum = 59;
    addr2.flat = 143;
    addr2.index = 953769;
    print(addr2);

    Address *addr3 = new Address;
    addr3->city = "SPB";
    addr3->street = "Lenina";
    addr3->homeNum = 55;
    addr3->flat = 666;
    addr3->index = 644109;
    print(*addr3);

    delete addr3;
    return 0;
}

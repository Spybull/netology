#include <iostream>
#include <string.h>
#include <fstream>

#define FILE_IN  "in.txt"
#define FILE_OUT "out.txt"
#define ROW_MAX 4

class address {
    public:

        address() {}
        address(std::string city, std::string street, uint houseNum, uint apartNum)
            : city(city),
              street(street),
              houseNum(houseNum),
              apartNum(apartNum)
        {}

        std::string getString() {
            return city + ", " + street + ", " + std::to_string(houseNum) + ", " + std::to_string(apartNum);
        }

    private:
        std::string city;
        std::string street;
        unsigned int houseNum;
        unsigned int apartNum;
};



int main()
{
    std::ifstream in(FILE_IN);

    if (!in) {
        std::cerr << "Error opening " << FILE_IN << std::endl;
        return -1;
    }

    std::string line;
    std::getline(in, line);

    int nAddr = std::stoi(line);
    if (nAddr <= 0) {
        std::cerr << "Error, size in first line cannot be <= zero!\n";
        return -2;
    }
    
    address *addr = new address[nAddr];
    std::string data[ROW_MAX];

    for(int i = 0; i < nAddr; ++i)
    {
        for(int j = 0; j < ROW_MAX; ++j)
        {
            std::getline(in, line);
            data[j] = line;
        }
        
        addr[i] = address(data[0], data[1], std::stoi(data[2]), std::stoi(data[3]));
    }

    std::ofstream out(FILE_OUT);

    if(!out) {
        std::cerr << "Error opening " << FILE_OUT << std::endl;
        return -3;
    }

    out << nAddr << "\n";
    for(int i = nAddr-1; i >= 0; --i)
        out << addr[i].getString() << "\n";


    in.close();
    out.close();
    delete []addr;
    return 0;
}
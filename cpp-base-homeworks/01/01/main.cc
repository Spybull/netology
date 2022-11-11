#include <iostream>
#include <fstream>
#include <string.h>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

typedef void (*swapFunc)(int *, int);

void rSwap(int *array, int sizeOfArray); // Swap by left  overflow
void lSwap(int *array, int sizeOfArray); // Swap by right overflow

int *getArrayFromLine(std::string line, int &arraySize, swapFunc swapper)
{
    char *subLine = strtok(const_cast<char *>(line.c_str()), " ");

    if (subLine == nullptr)
        return nullptr;

    int *tmp = new int[arraySize];
    memset(tmp, 0, sizeof(int) * arraySize);

    int countChar = 0;

    while(subLine != nullptr)
    {
        if ( countChar+1 > arraySize ) {
            std::cout << "WARNING: Wrong array size in first line, "
                      << "only " << countChar << " elements will be in array!\n";
            break;
        }

        tmp[countChar] = static_cast<int>(std::stoi(subLine));
        subLine = strtok(nullptr, " ");
        ++countChar;
    }

    if (countChar < arraySize) {
        std::cout << "WARNING: Wrong array size "
                  << "operate only " << countChar << " elements!\n";
    }

    arraySize = countChar;
    swapper(tmp, arraySize);

    return tmp;
}

int main()
{
    const int maxL = 4;
    std::string line[maxL];
    int lineCheck = 0;

    std::ifstream in(INPUT_FILE);

    if (!in) {
        std::cerr << "Error ifstream\n";
        return -1;
    }

    // Get size of arrays
    while (!in.eof() && lineCheck < maxL) {
        std::getline(in, line[lineCheck]);

        if (line[lineCheck].empty()) {
            std::cerr << "Not enough lines in " << INPUT_FILE << std::endl;
            return -2;
        }
        ++lineCheck;
    }
    
    int sz1 = std::stoi(line[0]);
    int sz2 = std::stoi(line[2]);

    int *arr1 = getArrayFromLine(line[1], sz1, lSwap);
    int *arr2 = getArrayFromLine(line[3], sz2, rSwap);

    // close input file
    in.close();

    std::ofstream out(OUTPUT_FILE);
    if (!out) {
        std::cerr << "Error ofstream\n";
        return -3;
    }

    out << sz2 << "\n";
    for(int i = 0; i < sz2; ++i)
        out << arr2[i] << " ";

    out << "\n";

    out << sz1 << "\n";
    for(int i = 0; i < sz1; ++i)
        out << arr1[i] << " ";

    std::cout << "Completed, see file " << OUTPUT_FILE << std::endl;

    out.close();
    delete []arr1;
    delete []arr2;

    return 0;
}

void lSwap(int *ptr, int sz) {

    int tmp[sz];

    for(int i = 1, j = 0; i < sz; ++i && ++j)
        tmp[j] = ptr[i];

    tmp[sz-1] = ptr[0];
    memcpy(ptr, tmp, sz * sizeof(int));
}

void rSwap(int *ptr, int sz) {

    int tmp[sz];

    for(int i = 1, j = 0; i < sz; ++i && ++j)
        tmp[i] = ptr[j];

    tmp[0] = ptr[sz-1];
    memcpy(ptr, tmp, sz*sizeof(int));
}
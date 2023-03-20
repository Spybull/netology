#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <list>

template<typename T>
void print_container(const T &cnt) {

    for(auto it = cnt.begin(); it != cnt.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);

    return 0;
}
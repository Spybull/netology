#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main()
{
    int n = 0, nn;
    std::set<int> v;

    std::cout << "[IN]: " << std::endl;
    std::cin >> n;
    
    for(int i = 0; i < n; ++i) {
        std::cin >> nn;
        v.insert(nn);
    }

    std::vector<int> as(v.begin(), v.end());
    std::sort(as.begin(), as.end(), [](const int &a, const int &b) {
        return a > b;
    });

    std::cout << "[OUT]: " << std::endl;
    for (const auto &i : as)
        std::cout << i << std::endl;

    return 0;
}
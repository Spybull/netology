#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef std::pair<char, int> pair;

int main()
{
    std::string s = "Hello world!!";
    std::map<char, int> mp;

    for(const auto &c : s) {
        if ( auto f = mp.find(c); f == mp.end() )
            mp.insert(std::make_pair(c, 1));
        else
            f->second++;
    }

    std::vector<pair> v;
    for(const auto &m : mp)
        v.push_back( std::make_pair(m.first, m.second) );
        

    std::sort(v.begin(), v.end(), [](const pair &a, const pair &b) {
        return a.second > b.second;
    });

    for (const auto &n : v)
        std::cout << n.first << " - " << n.second << std::endl;

    return 0;
}
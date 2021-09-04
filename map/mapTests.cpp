#include <iostream>
#include <map>
#include "map.hpp"
#include "iterator.hpp"
#include <utility>

int main()
{
    ft::map<int, int> mp;
    ft::map<int, int> mp1;

    std::map<int,int> mm;
    for (int i = 0; i < 10; i++)
        mp.insert(std::pair<int, int>(i, i*10));
    ft::map<int, int>::iterator it = mp.begin();
    while(it != mp.end())
    {
        std::cout << (*it).first << std::endl;
        it++;
    }
    std::cout << mp.find(2)->second;
    return 0;
}
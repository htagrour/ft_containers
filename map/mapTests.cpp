#include <iostream>
#include <map>
#include "map.hpp"
#include "iterator.hpp"
#include <utility>

int main()
{
    ft::map<int, int> mp;
    ft::map<int, int> mp1;

    // ft::map<int, int>::iterator it;
    std::map<int,int> mm;
    for (int i = 0; i < 10; i++)
        mp.insert({i, i*10});
    for (ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        std::cout << (*it).first << std::endl;

    std::cout << mp.find(2)->second;
}
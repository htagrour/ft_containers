#include "list/List.hpp"
#include <iostream>
#include <list>

int main()
{
    {
        std::cout << "-----LIST--------" << std::endl;
        ft::list<int> _listi;
        
        std::cout << "IS_EMPTY: "<< _listi.empty() << std::endl;
        for (int i = 1; i < 100;i++)
            _listi.push_back(i);
        _listi.pop_back();
        for(ft::list<int>::iterator it = _listi.begin() ; it != _listi.end(); it++)
        {
            *it *= 10;
            std::cout << *it << std::endl;
        }
        std::cout << "IS_EMPTY: "<< _listi.empty() << std::endl;
        std::cout << "SIZE: "<< _listi.size() << std::endl;
        std::cout << "FRONT :" << _listi.front() << std::endl;
        std::cout << "BACK :" << _listi.back() << std::endl;
        std::cout << "-----------------" << std::endl;
    }

    return (0);
}
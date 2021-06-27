#include "list/List.hpp"
#include <iostream>
#include <list>

template <typename T>
void print(T& var)
{
    for(typename T::iterator it = var.begin() ; it != var.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "IS_EMPTY: "<< var.empty() << std::endl;
    std::cout << "SIZE: "<< var.size() << std::endl;
    std::cout << "FRONT :" << var.front() << std::endl;
    std::cout << "BACK :" << var.back() << std::endl;
    std::cout << "MAX_SIZE: " << var.max_size() << std::endl;
}

int main()
{
    {
        std::cout << "-----LIST--------" << std::endl;
        ft::list<int> _listi;
        ft::list<int> _listi1;

        
        std::cout << "IS_EMPTY: "<< _listi.empty() << std::endl;
        for (int i = 1; i < 100;i++)
            _listi.push_back(i);
        // print<ft::list<int>>(_listi);
        _listi.assign(5,200);
        _listi1.assign(_listi.begin(), _listi.end());
        print< ft::list<int> >(_listi);
        std::cout << "-----------------" << std::endl;
    }

    return (0);
}
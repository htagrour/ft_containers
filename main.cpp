#include "list/List.hpp"
#include <iostream>
#include <list>
int main()
{
    {
        std::cout << "-----LIST--------" << std::endl;
        ft::list<std::string> _listi;
        
        for (int i = 1; i < 1001;i++)
            _listi.push_back("hi");
        for(ft::list<std::string>::ResverseIterator it = _listi.rbegin() ; it != _listi.rend(); it++)
        {
            std::cout << *it << std::endl;
        }
    }

    return (0);
}
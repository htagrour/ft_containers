#include <exception>
#include <iostream>
// allocators >>
#include "list/ListUtils.hpp"
// #include "list/List.hpp"
#include <memory>
#include <list>
#include <type_traits>



int main()
{
    std::list<int> lst;

    lst.insert(lst.begin(), 15);
    lst.insert(lst.begin(), 15);
    std::cout << *lst.end() << std::endl;
    return (0);
}

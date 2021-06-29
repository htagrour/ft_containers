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
    std::list<std::string> lst;

    std::cout << lst.back();
    return (0);
}

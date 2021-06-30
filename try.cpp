#include <exception>
#include <iostream>
// allocators >>
#include "list/ListUtils.hpp"
// #include "list/List.hpp"
#include <memory>
#include <list>
#include <type_traits>
#include "vector/vector.hpp"
#include <vector>
#include <typeinfo>

template <typename T>

void fun(T first, T end)
{
    std::cout << "IKHAN" << std::endl;
}

int main()
{
    int arr[4] = {1 , 2 , 5, 6};
    ft::VectIterator<int> it = arr;

    fun<ft::VectIterator<int> >(arr, arr+ 1);
    // for (; it != arr - 1; it++)
        // std::cout << *it << std::endl;
    return (0);
}

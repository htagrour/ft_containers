#include <exception>
#include <iostream>
// allocators >>
#include "list/ListUtils.hpp"
#include "list/List.hpp"
#include <memory>
#include <list>

typedef typename std::allocator<int>::template rebind<Node<int>>::other _node_all; 
int main()
{
    ft::list<int> l;

    l.assign(1, 1);
    return (0);
}
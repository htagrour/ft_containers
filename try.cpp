#include <exception>
#include <iostream>
// allocators >>
#include "list/ListUtils.hpp"
#include <memory>
#include <list>

int main()
{
    Node<int> *head;
    std::allocator< Node<int> > alloc;
    std::list<int> l;
    head = alloc.allocate(sizeof( Node<int> ));
    // alloc.deallocate(head, sizeof( Node<int> ));
    head = alloc.allocate(sizeof( Node<int> ));
    while(1){}

    return (0);
}
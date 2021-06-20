#ifndef FTLIST_HPP
#define FTLIST_HPP

#include <memory>

template<typename T, typename Alloc = std::allocator<T> >
class list
{
    private:
        /* data */
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        
};

#endif
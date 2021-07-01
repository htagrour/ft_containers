#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "VectorUtils.hpp"

namespace ft
{
    template <typename T, typename Alloc = std::allocator<T> >
    class vector
    {
        public:
                typedef T value_type;
                typedef Alloc allocator_type;
                typedef typename allocator_type::reference reference;
                typedef typename allocator_type::const_reference const_reference;
                typedef typename allocator_type::pointer pointer;
                typedef typename allocator_type::const_pointer const_pointer;
                typedef std::size_t size_type;
                typedef std::ptrdiff_t difference_type;
                typedef ft::VectIterator <value_type> iterator;
                // typedef ConstIterator<value_type> const_iterator;
                typedef ft::RevereVectIterator<value_type> reverse_iterator;

                explicit vector(const allocator_type& alloc = allocator_type()):_alloc(alloc)
                {

                }
                explicit vector (size_type n, const value_type& val = value_type(),
                                const allocator_type& alloc = allocator_type())
                                {}
                template <typename InputIterator>
                vector(InputIterator first, InputIterator last,
                        const allocator_type& alloc = allocator_type())
                        {}
                vector(const vector& x){}
        private:
            allocator_type _alloc;
            value_type *_data;
    };
}

#endif
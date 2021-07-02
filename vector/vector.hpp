#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "VectorUtils.hpp"
#include "../utils/utils.hpp"

#define DEFAUL_SIZE 4
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
                typedef ConstIterator<value_type> const_iterator;
                typedef ft::RevereVectIterator<value_type> reverse_iterator;

                /*
                        constructor/deconstructor
                */

                explicit vector(const allocator_type& alloc = allocator_type()):_alloc(alloc)
                {
                        _size = 0;
                        _capacity = 0;
                        _data = NULL;
                }
                explicit vector (size_type n, const value_type& val = value_type(),
                                const allocator_type& alloc = allocator_type())
                        {
                                _data = _alloc.allocate(n);
                                for (size_type i = 0; i < n; i++)
                                        _alloc.construct(_data + i, val);
                                _capacity = _size = n;
                        }
                template <typename InputIterator>
                vector(InputIterator first, InputIterator last,
                        const allocator_type& alloc = allocator_type())
                        {}
                vector(const vector& rsh)
                {
                        *this = rsh;
                }

                vector& operator=(const vector& rsh)
                {
                        if (this != &rsh)
                        {
                                if (_capacity)
                                        this->clear();
                                //assign
                        }
                }
                reference operator[](size_type index) {return _data[index];}
                const_reference operator[] (size_type n) const{ return _data[index];};

                /*
                        Capacity
                */

                size_type size() const{ return _size;};
                bool empty() const{ return !_size;};
                size_type max_size() const {return _alloc.max_size();}
                size_type capacity() const { return _capacity;}
                void reserve (size_type n)
                {
                        if (n > _capacity)
                                resize();
                }
                void resize (size_type n, value_type val = value_type())
                {
                        if (n < _size)
                        {
                                for (size_type i = n; i < _size; i++)
                                        _alloc.destroy(_data + i);
                                _size = n;
                        }
                        else
                        {
                                if (n > _capacity)
                                {
                                        reallocate(n);
                                        resize(n, val);
                                }
                                else
                                {
                                        for (size_type i = _size; i < n; i++)
                                                _alloc.construct(_data + i, val);
                                        _size = n;
                                }
                        }
                }
                /*
                        Iterators
                */
                iterator begin(){ return iterator(_data);}
                // const_iterator begin() const;
                iterator end(){ return iterator(_data + _size);}


                void assign (size_type n, const value_type& val)
                {
                        // if (n > _capacity)
                }
                void clear()
                {
                        if (_size)
                        {
                                for (size_type i = 0; i < _size ; i++)
                                        _alloc.destroy(_data + i);
                                _alloc.deallocate(_data, _capacity);
                                _capacity = _size  = 0;
                        }
                }
                
        private:
                void reallocate(size_type n)
                {
                        pointer new_arr;

                        if (n > _capacity)
                        {
                                new_arr = _alloc.allocate(n + DEFAUL_SIZE);
                                for (size_type  i = 0; i < _size; i++)
                                {
                                        _alloc.construct(new_arr + i,_data[i]);
                                        _alloc.destroy(_data + i);
                                }
                                _alloc.deallocate(_data, _capacity);
                                _data = new_arr;
                                _capacity = n;
                        }
                }
        private:
            allocator_type _alloc;
            pointer _data;
            size_type _size;
            size_type _capacity;
    };
}

#endif
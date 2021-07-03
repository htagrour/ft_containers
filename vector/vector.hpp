#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "VectorUtils.hpp"
#include "../utils/utils.hpp"
#include <exception>

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

                class BadAlloc: public std::exception
                {
                        public:
                                const char* what() const throw()
                                {
                                        return ("bad_alloc");
                                }
                };
                /*
                        constructor/deconstructor
                */

                explicit vector(const allocator_type& alloc = allocator_type()):_alloc(alloc)
                {
                        zero();
                }
                explicit vector (size_type n, const value_type& val = value_type(),
                                const allocator_type& alloc = allocator_type()): _alloc(alloc)
                        {
                                zero();
                                assign(n, val);
                        }
                template <typename InputIterator>
                vector(InputIterator first, InputIterator last,
                        const allocator_type& alloc = allocator_type(),
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL):_alloc(alloc)
                        {
                                zero();
                                assign(first, last);
                        }
                
                vector(const vector& rsh)
                {
                        *this = rsh;
                }

                vector& operator=(const vector& rsh)
                {
                        if (this != &rsh)
                        {
                                clear();
                                assign(rsh.begin(), rsh.end());
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

                void reserve (size_type n) throw(BadAlloc)
                {
                        pointer new_arr;

                        if (n <= 0 || n >= max_size())
                                throw(BadAlloc());
                        if (n > _capacity)
                        {
                                try
                                {
                                        new_arr = _alloc.allocate(n);
                                }
                                catch(std::exception &e)
                                {
                                        throw(BadAlloc());
                                }
                                if (_size)
                                {
                                        for (size_type  i = 0; i < _size; i++)
                                        {
                                                _alloc.construct(new_arr + i,_data[i]);
                                                _alloc.destroy(_data + i);
                                        }
                                        _alloc.deallocate(_data, _capacity);
                                }
                                _data = new_arr;
                                _capacity = n;
                        }
                }

                void resize (size_type n, value_type val = value_type())
                {
                        if (n < _size)
                        {
                                destroy_element(n);
                                _size = n;
                        }
                        else
                        {
                                if (n > _capacity)
                                {
                                        reserve(n);
                                        resize(n, val);
                                }
                                else
                                {
                                        construct_element(n,val);
                                        _size = n;
                                }
                        }
                }
                /*
                        Iterators
                */
                iterator begin(){ return iterator(_data);}
                const_iterator begin() const return (const_iterator(_data));
                iterator end(){ return iterator(_data + _size);}

                /*
                        Modifiers:
                */
                template <class InputIterator>
                void assign (InputIterator first, InputIterator last,
                             typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
                {
                        pointer _temp;
                        difference_type diff = (last - first);

                        if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) ==\
                                typeid(typename ft::iterator_traits<InputIterator>::iterator_category))
                                {
                                        reserve(diff);
                                        _temp = _data;
                                        for (InputIterator it = first; it != last; it++)
                                                _alloc.construct(_data++, *it);
                                        _data = _temp;
                                        _size = diff;
                                    }
                }

                void assign (size_type n, const value_type& val)
                {
                        destroy_element(_size);
                        resize(n, val);
                }

                void clear()
                {
                        if (_capacity)
                        {
                                destroy_element(_size);
                                _alloc.deallocate(_data, _capacity);
                        }
                        zero();
                }
        private:
                void zero()
                {
                        _size = 0;
                        _capacity = 0;
                        _data = NULL;
                }
                void destroy_element(size_type n)
                {
                        for (size_type i = n; i < _size; i++)
                                _alloc.destroy(_data + i);
                        _size = 0;
                }
                void construct_element(size_type n,const value_type& val) //!!!!!!!!!!
                {
                        for (size_type i = _size; i < n; i++)
                                _alloc.construct(_data + i, val);
                }
        private:
            allocator_type _alloc;
            pointer _data;
            size_type _size;
            size_type _capacity;
    };
}
template <typename T>
std::ostream &operator<<(std::ostream &os, ft::vector<T> &rsh)
{
        os << "Size:" << rsh.size() << std::endl;
        os << "Capacity:" << rsh.capacity() << std::endl;
        os << "Empty:" << rsh.empty() << std::endl;
        os << "Max_size:" << rsh.max_size() << std::endl; 

        os << "Content:" << std::endl;
        for (typename ft::vector<T>::iterator it = rsh.begin(); it != rsh.end(); it++)
                std::cout << *it << std::endl;
        return (os);
}
#endif

//  typename ft::enable_if<(typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(typename ft::iterator_traits<InputIterator>::iterator_category)), InputIterator>::type* = NULL
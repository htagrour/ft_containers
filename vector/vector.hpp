#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "VectorUtils.hpp"
#include "../utils/utils.hpp"
#include <iostream>
#include <exception>
#include <typeinfo>
#include "../utils/reverse_iterator.hpp"
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
                typedef ft::VectIterator<const value_type> const_iterator;
                typedef ft::reverseIterator<iterator> reverse_iterator;
                typedef ft::reverseIterator<const_iterator> const_reverse_iterator;

                class BadAlloc: public std::exception
                {
                        public:
                                const char* what() const throw()
                                {
                                        return ("bad_alloc");
                                }
                };

                class OutOfRange :public std::exception
                {
                        public:
                                const char * what() const throw()
                                {
                                        return ("out of range");
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
                        zero();
                        *this = rsh;
                }

                vector& operator=(const vector& rsh)
                {
                        if (this != &rsh)
                        {
                                clear();
                                if (rsh.size())
                                        assign(rsh.begin(), rsh.end());
                        }
                        return *this;
                }


                /*
                        Iterators
                */
                iterator begin(){ return iterator(_data);}
                const_iterator begin() const {return (const_iterator(_data));}
                reverse_iterator rbegin() { return reverse_iterator(_data + _size - 1);};
                const_reverse_iterator rbegin() const { return const_reverse_iterator(_data + _size - 1);};

                iterator end(){ return iterator(_data + _size);}
                const_iterator end() const {return (const_iterator(_data + _size));}
                reverse_iterator rend() { return reverse_iterator(_data - 1);}
                const_reverse_iterator rend() const { return const_reverse_iterator(_data - 1);};


                /*
                        Capacity
                */

                size_type size() const{ return _size;};
                bool empty() const{ return !_size;};
                size_type max_size() const {return _alloc.max_size();}
                size_type capacity() const { return _capacity;}

                void reserve (size_type n)
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

                                for (size_type  i = 0; i < _size; i++)
                                {
                                        _alloc.construct(new_arr + i,_data[i]);
                                        _alloc.destroy(_data + i);
                                }
                                if (_data)
                                        _alloc.deallocate(_data, _capacity); // moxkil pop and resize
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
                        Element access
                */
                reference operator[](size_type index) {return _data[index];}
                const_reference operator[] (size_type index) const{ return _data[index];};
                reference at(size_type n)
                {
                        if (n < 0 || n >= _size)
                                throw(OutOfRange());
                        return (_data[n]);
                }

                const_reference at(size_type n) const
                {
                        if (n < 0|| n >= _size)
                                throw(OutOfRange());
                        return (_data[n]);
                }

                reference front() { return _data[0];}
                const_reference front() const { return _data[0];};
                reference back() { return _data[_size - 1];}
                const_reference back() const { return _data[_size - 1];};
                /*
                        Modifiers:
                */
                template <class InputIterator>
                void assign (InputIterator first, InputIterator last,
                             typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
                {
                        pointer _temp;
                        difference_type diff = std::distance(first, last);

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

                void push_back (const value_type& val)
                {
                        if (_size + 1 > _capacity)
                                reserve((_size + 1) * 2);
                        _alloc.construct(_data + _size++, val);
                }
                
                void pop_back()
                {
                        if (_size)
                        {
                                _alloc.destroy(_data + _size -1);
                                _size--;
                        }
                }

                iterator insert (iterator position, const value_type& val)
                {
                        return insert_helper(position, 1,val);
                }

                void insert (iterator position, size_type n, const value_type& val)
                {
                        insert_helper(position,n, val);
                }

                template <class InputIterator>
                void insert (iterator position, InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
                {
                        iterator pos = position;

                        if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) ==\
                            typeid(typename ft::iterator_traits<iterator>::iterator_category) &&
                            std::distance(first, last) >= 0)
                            {
                                for (InputIterator it = first; it != last; it++)
                                        position = insert_helper(position, 1, *it);
                            }
                            // 
                }

                iterator erase (iterator position)
                {
                        return (erase_helper(position, 1));
                }

                iterator erase (iterator first, iterator last)
                {
                        return(erase_helper(first, last - first));
                }

                void swap (vector& x)
                {
                        vector tmp(*this);

                        *this = x;
                        x = tmp;
                }

                void clear()
                {
                        if (_capacity)
                        {
                                destroy_element(_size);
                                // _alloc.deallocate(_data, _capacity);
                        }
                        // zero();
                }
                /*
                        Allocator
                */

               allocator_type get_allocator() const
               {
                       return (allocator_type(_alloc));
               }
               /*
                        relational operators
               */
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

                void shift_right_data(size_type index, size_type number)
                {
                        value_type tmp;
                        value_type tmp1;

                        for(size_type n = 0; n < number; n++)
                        {
                                tmp = _data[index];
                                for(size_type i = index; i < _size + number; i++)
                                {
                                        tmp1 = _data[i + 1];
                                        _data[i + 1] = tmp;
                                        tmp = tmp1;
                                }
                        }
                } // it's work now but i don't know why!!!

                void shift_left_data(size_type index, size_type number)
                {
                        value_type tmp;
                        value_type tmp1;

                        for (size_type n = 0; n < number; n++)
                        {
                                tmp = _data[_size - 1];
                                for(int i = _size - 1; i > index; i--)
                                {
                                        tmp1 = _data[i - 1];
                                        _data[i - 1] = tmp;
                                        tmp = tmp1;
                                }
                        }
                }

                iterator insert_helper(iterator position, size_type n, const value_type& val)
                {
                        difference_type index = std::distance(begin(), position);
                        if (_size + n > _capacity)
                                reserve(_size + n + DEFAUL_SIZE);
                        shift_right_data(index, n);
                        for (size_type i = index; i < index + n; i++)
                                _alloc.construct(_data + i, val);
                        _size += n;
                        return (iterator(_data + index));
                }

                iterator erase_helper(iterator position, size_type n)
                {
                        difference_type index = std::distance(begin(), position);
                        if (index >= 0 && index < _size)
                        {
                                for (size_type i = index; i < index + n; i++)
                                        _alloc.destroy(_data + i);
                                shift_left_data(index, n);
                                _size -= n;
                        }
                        return (iterator(_data + index));   
                }
                ~vector(){clear()};
        private:
            allocator_type _alloc;
            pointer _data;
            size_type _size;
            size_type _capacity;
    };
        /*
                Non-member function overloads
        */
        template <typename  T, typename Alloc>
        void swap (vector<T,Alloc>& lsh, vector<T,Alloc>& rsh)
        {
                lsh.swap(rsh);
        }

        template <class T, class Alloc>
        bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rsh)
        {
                if (lhs.size() != rsh.size())
                        return (false);
                return (ft::eqaul(lhs.begin(), lhs.end(), rsh.begin(), rsh.end()));
        }

        template <class T, class Alloc>
        bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rsh)
        {
                return (!(lhs == rsh));
        }

        template <class T, class Alloc>
        bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {
                if (lhs.size() < rhs.size())
                        return (true);
                if (lhs.size() > rhs.size())
                        return (false);
                return(ft::lexicographical_compare(lhs.begin(),lhs.end(), rhs.begin(), rhs.end()));
        }

        template <class T, class Alloc>
        bool operator<=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {
                return(!(lhs > rhs));
        }

        template <class T, class Alloc>
        bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {
                return (rhs < lhs);
        }

        template <class T, class Alloc>
        bool operator>=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
        {
                return(!(lhs < rhs));
        }



}



template <typename T>
std::ostream &operator<<(std::ostream &os, ft::vector<T> &rsh)
{
        os << "Size:" << rsh.size() << std::endl;
        os << "Capacity:" << rsh.capacity() << std::endl;
        os << "Empty:" << rsh.empty() << std::endl;
        os << "Max_size:" << rsh.max_size() << std::endl; 
        os << "Front:" << rsh.front() << std::endl;
        os << "Back:" << rsh.back() << std::endl;

        os << "Content:" << std::endl;
        for (typename ft::vector<T>::iterator it = rsh.begin(); it != rsh.end(); it++)
                std::cout << *it << std::endl;
        return (os);
}
#endif

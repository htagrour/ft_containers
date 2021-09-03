#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
namespace ft
{
    template<typename T>
    class iterator
    {
        public:
                typedef std::bidirectional_iterator_tag iterator_category;
                typedef std::ptrdiff_t difference_type;
                typedef T value_type;
                typedef value_type* pointer;
                typedef value_type& reference;
                typedef typename value_type::value_type base_type;

                iterator():_ptr(NULL){}
                iterator(pointer ptr):_ptr(ptr){}
                iterator(const iterator &rsh) { *this = rsh;}
                iterator& operator=(const iterator &rsh)
                {
                    if (this != &rsh)
                    {
                        _ptr = rsh._ptr;
                    }
                    return (*this);
                }

                iterator operator++(int)
                {
                    iterator tmp(*this);

                    ++*this;
                    return(tmp);
                }

                iterator& operator++()
                {
                    if (_ptr)
                    {
                        if (_ptr->_right)
                        {
                            _ptr = _ptr->_right;
                            while (_ptr->_left)
                                _ptr = _ptr->_left;
                        }
                        else
                            _ptr = _ptr->_parent;
                    }
                    return (*this);                                             
                }
                
                iterator operator--(int)
                {
                    iterator tmp(*this);

                    --*this;
                    return(tmp);
                }
                iterator& operator--()
                {
                    if (_ptr)
                    {
                        if (_ptr->_left)
                        {
                            _ptr = _ptr->_left;
                        }
                        else
                            _ptr = _ptr->_parent;
                    }
                    return (*this);
                }
                base_type& operator*(){ return _ptr->_data;}
                base_type* operator->(){return &_ptr->_data;}

                operator iterator<const T>() const {return (iterator<const T>(this->_ptr));}
                bool operator==(const iterator &rsh) { return _ptr == rsh._ptr;}
                bool operator!=(const iterator &rsh) { return _ptr != rsh._ptr;}


        private:
            pointer _ptr;
    };
}
#endif
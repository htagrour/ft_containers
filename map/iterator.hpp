#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "utils.hpp"
#include <iostream>
namespace ft
{
    template<typename T, typename Node>
    class iterator
    {
        public:
                typedef std::bidirectional_iterator_tag iterator_category;
                typedef std::ptrdiff_t difference_type;
                typedef T* pointer;
                typedef T& reference;



                iterator():_ptr(NULL){}
                iterator(Node* ptr):_ptr(ptr){}

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
                    Node* tmp;

                    if (_ptr)
                    {
                        if (_ptr->_right)
                        {
                            _ptr = _ptr->_right;
                            while (_ptr && _ptr->_left)
                                _ptr = _ptr->_left;
                        }
                        else
                        {
                            tmp = _ptr->_parent;
                            while(tmp && _ptr == tmp->_right)
                            {
                                _ptr = tmp;
                                tmp = tmp->_parent;
                            }
                            _ptr = tmp;
                        }
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
                    Node* tmp;

                    if (_ptr)
                    {
                        if (_ptr->_left)
                        {
                            _ptr = _ptr->_left;
                            while(_ptr && _ptr->_right)
                                _ptr = _ptr->_right;
                        }
                        else
                        {
                            tmp = _ptr->_parent;
                            while(tmp != NULL && _ptr == tmp->_left)
                            {
                                _ptr = tmp;
                                tmp = tmp->_parent;
                            }
                            _ptr = tmp;
                        }
                    }
                    return (*this);
                }
                reference operator*() { return *_ptr->_data;}
                pointer operator->(){ return _ptr->_data;}
                operator iterator<const T,  Node>() const { 
                    return (iterator<const T, Node>(this->_ptr));
                }
                bool operator==(const iterator &rsh) { return _ptr == rsh._ptr;}
                bool operator!=(const iterator &rsh) { return _ptr != rsh._ptr;}
                Node* getBase() const {return _ptr;}
        private:
            Node* _ptr;
    };
}
#endif
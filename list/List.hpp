#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <cstddef>
#include "ListUtils.hpp"

namespace ft
{
    template<typename T , typename Alloc = std::allocator<T> >
    class list
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
            typedef Iterator<value_type> iterator;
            // typedef implementation-defined constiterator;
            typedef ResverseIterator<value_type> reverse_iterator;
            // typedef reverse_iterator<constiterator> const_reverse_iterator;

            list()
            {
                _head = _tail = NULL;
                _size = 0;
            }
            ~list()
            {
                Node<value_type> *tmp;

                if (_head)
                {
                    while(_head)
                    {
                        tmp = _head->next;
                        delete _head;
                        _head = tmp;
                    }
                }
            }
            /*
                ITERATORS
            */

            iterator begin(){return (iterator(this->_head));}
            reverse_iterator rbegin()
            {
                return (reverse_iterator(_tail));
            }
            iterator end(){return (iterator(nullptr));}
            reverse_iterator rend(){return (reverse_iterator(nullptr));}
            /*
                CAPACITY
            */
            bool empty() const { return (!_head);}
            size_type size() const { return (_size);}
            // size_type max_size() const { return ()}

            /*
                ELEMENT ACCESS
            */

            reference front() const { return (_head->data);}
            reference back() const { return (_tail->data);}

            /*
                MODIFIERS
            */

            void push_front(const value_type& value)
            {
                Node<value_type> *new_node = new Node<value_type>(value);

                if (!_head)
                    _head = _tail = new_node;
                else
                {
                    _head->prev = new_node;
                    new_node->next = _head;
                    _head = new_node;
                }
                _size += 1;
            }

            void pop_front()
            {
                Node<value_type> *tmp;

                if (_head)
                {
                    tmp = _head->next;
                    delete _head;
                    _head = tmp;
                    _head->prev = nullptr;
                    _size--;
                }
            }

            void pop_back()
            {
                Node<value_type> *tmp;

                if (_tail)
                {
                    tmp = _tail->prev;
                    delete _tail;
                    _tail = tmp;
                    _tail->next = nullptr;
                    _size--;
                }
            }
            void push_back(const value_type& value)
            {
                Node<value_type> *new_node = new Node<value_type>(value);

                if (!_head)
                    _head = _tail = new_node;
                else
                {
                    _tail->next = new_node;
                    new_node->prev = _tail;
                    _tail = new_node;
                }
                _size += 1;
            }
        private:
            Node<value_type>* _head;
            Node<value_type>* _tail;
            size_type _size;
    };

}

#endif

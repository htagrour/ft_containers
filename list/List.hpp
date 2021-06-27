#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <cstddef>
#include "ListUtils.hpp"
#include "../utils/utils.hpp"

namespace ft
{
    template<typename T , typename Alloc = std::allocator<T> >
    class list
    {
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef Node<value_type> node;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::template rebind<node>::other node_alloc;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;
            typedef Iterator<value_type> iterator;
            typedef ConstIterator<value_type> const_iterator;
            typedef ResverseIterator<value_type> reverse_iterator;
            // typedef reverse_iterator<constiterator> const_reverse_iterator;

            list()
            {
                _head = _tail = NULL;
                _size = 0;
            }
            ~list()
            {
                this->clear();
            }
            /*
                ITERATORS
            */

            const_iterator begin() const {return (const_iterator(this->_head));}
            iterator begin(){return (iterator(this->_head));}
            reverse_iterator rbegin()
            {
                return (reverse_iterator(_tail));
            }
            const_iterator end() const {return (const_iterator(nullptr));}
            iterator end(){return (iterator(nullptr));}
            reverse_iterator rend(){return (reverse_iterator(nullptr));}
            /*
                CAPACITY
            */
            bool empty() const { return (!_head);}
            size_type size() const { return (_size);}
            size_type max_size() const{ return (_my_alloc.max_size());};

            /*
                ELEMENT ACCESS
            */

            const_reference front() const { return (_head->data);}
            reference front() { return (_head->data);}
            const_reference back() const { return (_tail->data);}
            reference back() { return (_tail->data);}

            /*
                MODIFIERS
            */

            void assign (size_type n, const value_type& val)
            {
                this->clear();
                for (size_type i = n; i > 0; i--)
                    this->push_back(val);
            }

            template <typename InputIterator >
            void assign(InputIterator first, InputIterator last , typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = 0)
            {
                this->clear();
                for (InputIterator it = first;it != last; it++)
                    this->push_back(*it);
            }
            


            void push_front(const value_type& value)
            {
                node *new_node;

                new_node = _my_alloc.allocate(1);
                _my_alloc.construct(new_node, node(value));
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
                node *tmp;

                if (_head)
                {
                    tmp = _head->next;
                    _my_alloc.destroy(_head);
                    _my_alloc.deallocate(_head);
                    _head = tmp;
                    _head->prev = nullptr;
                    _size--;
                }
            }

            void pop_back()
            {
                node *tmp;

                if (_tail)
                {
                    tmp = _tail->prev;
                    _my_alloc.destroy(_tail);
                    _my_alloc.deallocate(_tail);
                    _tail = tmp;
                    _tail->next = nullptr;
                    _size--;
                }
            }
            void push_back(const value_type& value)
            {
                node *new_node;
                new_node = _my_alloc.allocate(1);
                _my_alloc.construct(new_node, node(value));

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
            void clear()
            {
                node *tmp;

                if (_head)
                {
                    while(_head)
                    {
                        tmp = _head->next;
                        _my_alloc.destroy(_head);
                        _my_alloc.deallocate(_head, 1);
                        _head = tmp;
                    }
                    _size = 0;
                }
            }
        private:
            node* _head;
            node* _tail;
            size_type _size;
            node_alloc _my_alloc;
    };

}

#endif

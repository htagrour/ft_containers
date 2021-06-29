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

            list(const alloc)
            {
                _head = _tail = create_node();
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
                return (reverse_iterator(_tail->prev));
            }
            const_iterator end() const {return (const_iterator(_tail));}
            iterator end(){return (iterator(_tail));}
            reverse_iterator rend(){return (reverse_iterator(_head->prev));}
            /*
                CAPACITY
            */
            bool empty() const { return (!_size);}
            size_type size() const { return (_size);}
            size_type max_size() const{ return (_my_alloc.max_size());};

            /*
                ELEMENT ACCESS
            */

            const_reference front() const { return (_head->data);}
            reference front() { return (_head->data);}
            const_reference back() const { return (_tail->prev->data);}
            reference back() { return (_tail->prev->data);}

            /*
                MODIFIERS
            */

            void assign (size_type n, const value_type& val)
            {
                this->clear();
                _head = _tail = create_node();
                for (size_type i = n; i > 0; i--)
                    this->push_back(val);
            }

            template <typename InputIterator  >
            void assign(InputIterator first, InputIterator last ,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type t = 0)
            {
                this->clear();
                _head = _tail = create_node();
                for (InputIterator it = first;it != last; it++)
                    this->push_back(*it);
                //check if an InputIteraor is valid
            }
            
            iterator insert(iterator position, const value_type& val)
            {
                node *new_node;

                //if !position
                    // throw(error);
                //insert before
                insert_before_node(position.m_ptr, val);
                return (position);
            }

            void push_front(const value_type& value)
            {
                _head = create_node(value, _head->prev, _head);
                _head->next->prev = _head;
                _size += 1;
            }

            void pop_front()
            {
                if (_head != _tail)
                {
                    _head = _head->next;
                    delete_node(_head->prev);
                }
            }

            void pop_back()
            {
                if (_tail != _head)
                    delete_node(_tail->prev);
            }

            void push_back(const value_type& value)
            {
                _tail->prev = create_node(value, _tail->prev, _tail);
                if (_tail->prev->prev)
                    _tail->prev->prev->next = _tail->prev;
                if (_tail == _head)
                    _head = _tail->prev;
                _size += 1;
            }

        private:

            void clear()
            {
                node *tmp;

                while(_head != _tail)
                {
                    tmp = _head->next;
                    _my_alloc.destroy(_head);
                    _my_alloc.deallocate(_head, 1);
                    _head = tmp;
                }
                _my_alloc.destroy(_tail);
                _my_alloc.deallocate(_tail, 1);
                _tail = NULL;
                _head = NULL;
                _size = 0;
            }
            
            node* create_node(const T& value, node* prev, node* next)
            {
                node *new_node;

                new_node = _my_alloc.allocate(1);
                _my_alloc.construct(new_node, node(value, next, prev));
                return (new_node);
            }

            node* create_node()
            {
                node *new_node;

                new_node = _my_alloc.allocate(1);
                _my_alloc.construct(new_node, node());
                return (new_node);
            }

            void delete_node(node *_node)
            {
                if (_node)
                {
                    if (_node->prev)
                        _node->prev->next = _node->next;
                    if (_node->next)
                        _node->next->prev = _node->prev;
                    _my_alloc.destroy(_node);
                    _my_alloc.deallocate(_node, 1);
                    _size--;
                }
            }

            // void insert_before_node(node *_node, const value_type& value)
            // {
            //     node *new_node;

            //     new_node = _my_alloc.allocate(1);
            //     if (!_node)
            //     {
            //         if (!_head)
                        
            //     }
            //     _my_alloc.construct(new_node, node(value, _node, _node->prev));
            //     if (_node == _head)
            //         _head = new_node;
            // }

        private:
            node* _head;
            node* _tail;
            size_type _size;
            node_alloc _my_alloc;
    };

}

#endif

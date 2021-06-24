#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
#include <cstddef>

template <typename T>
class Node
{
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
        Node():next(nullptr),prev(nullptr){}
        Node(const T& value):data(value), next(nullptr), prev(nullptr){}
};

namespace ft
{
    template<typename T , typename Alloc = std::allocator<T> >
    class list
    {
        public:
            typedef T value_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;
            
            class Iterator
            {
                public:
                    Iterator(Node<value_type> *ptr):m_ptr(ptr){}
                    reference operator*() const { return m_ptr->data; }
                    // pointer operator->() { return m_ptr; }
                    Iterator& operator++() { m_ptr = m_ptr->next; return *this; } 
                    Iterator operator++(int)
                    {
                        Iterator tmp = *this;
                        m_ptr = m_ptr->next;
                        return tmp;
                    }
                    Iterator& operator--() { m_ptr = m_ptr->prev; return *this; } 
                    Iterator operator--(int)
                    {
                        Iterator tmp = *this;
                        m_ptr = m_ptr->prev;
                        return tmp;
                    } 
                    bool operator!=(const Iterator& rsh){return (this->m_ptr != rsh.m_ptr);}
                    bool operator==(const Iterator& rsh){return (this->m_ptr == rsh.m_ptr);}

                private:
                    Node<value_type> *m_ptr;
            };

            class ResverseIterator
            {
                public:
                    ResverseIterator(Node<value_type> *ptr):m_ptr(ptr){}
                    reference operator*() const { return m_ptr->data; }
                    // pointer operator->() { return m_ptr; }
                    ResverseIterator& operator++() { m_ptr = m_ptr->prev; return *this; } 
                    ResverseIterator operator++(int)
                    {
                        ResverseIterator tmp = *this;
                        m_ptr = m_ptr->prev;
                        return tmp;
                    }
                    ResverseIterator& operator--() { m_ptr = m_ptr->next; return *this; } 
                    ResverseIterator operator--(int)
                    {
                        ResverseIterator tmp = *this;
                        m_ptr = m_ptr->next;
                        return tmp;
                    } 
                    bool operator!=(const ResverseIterator& rsh){return (this->m_ptr != rsh.m_ptr);}
                    bool operator==(const ResverseIterator& rsh){return (this->m_ptr == rsh.m_ptr);}

                private:
                    Node<value_type> *m_ptr;
            };

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

            Iterator begin(){return (Iterator(this->_head));}
            ResverseIterator rbegin()
            {
                return (ResverseIterator(_tail));
            }
            Iterator end(){return (Iterator(nullptr));}
            ResverseIterator rend(){return (ResverseIterator(nullptr));}
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
                    tmp = _head->prev;
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

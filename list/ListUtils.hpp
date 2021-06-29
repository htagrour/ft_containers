#ifndef LISTUTILS_HPP
#define LISTUTILS_HPP
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
        // Node(const T& value):data(value), next(nullptr), prev(nullptr){}
        Node(const T& value, Node<T> *_next, Node<T> *_prev): data(value), next(_next), prev(_prev){}
};

template <typename T>
class Iterator
{
    public:
        typedef T value_type;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        Iterator(Node<T> *ptr):m_ptr(ptr){}
        reference operator*() const { return m_ptr->data; }
        // pointer operator->() { return m_ptr; }

        Iterator& operator=(const Iterator &rsh)
        {
            if (this != &rsh)
            {
                this->m_ptr = rsh.m_ptr;
            }
            return (*this);
        }
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

    // private:
        Node<T> *m_ptr;
};

template <typename T>
class ConstIterator:public Iterator<T>
{
    public:
        typedef T value_type;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        ConstIterator(Node<T> *ptr):m_ptr(ptr){}
        const_reference operator*() const { return m_ptr->data; }
        // const_pointer operator->() { return m_ptr; }
        ConstIterator& operator++() { m_ptr = m_ptr->next; return *this; } 
        ConstIterator operator++(int)
        {
            ConstIterator tmp = *this;
            m_ptr = m_ptr->next;
            return tmp;
        }
        ConstIterator& operator=(const ConstIterator &rsh)
        {
            if (this != &rsh)
            {
                this->m_ptr = rsh.m_ptr;
            }
            return (*this);
        }
        ConstIterator& operator--() { m_ptr = m_ptr->prev; return *this; } 
        ConstIterator operator--(int)
        {
            ConstIterator tmp = *this;
            m_ptr = m_ptr->prev;
            return tmp;
        } 
        bool operator!=(const ConstIterator& rsh){return (this->m_ptr != rsh.m_ptr);}
        bool operator==(const ConstIterator& rsh){return (this->m_ptr == rsh.m_ptr);}

    private:
        Node<T> *m_ptr;
};


template<typename T>
class ResverseIterator
{
    public:
    
        typedef T value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        ResverseIterator(Node<T> *ptr):m_ptr(ptr){}
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
        Node<T> *m_ptr;
};
#endif
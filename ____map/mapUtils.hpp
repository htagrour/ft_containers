#ifndef MAPUTILS_HPP
#define MAPUTILS_HPP
#include <iterator>

namespace ft
{
    template <typename T1, typename T2>
    class pair
    {
        public:
            typedef T1 first_type;
            typedef T2 second_type;

            first_type first;
            second_type second;
            pair(){};
            pair(const first_type& a, const second_type& b): first(a), second(b){}
            template<class U, class V>
            pair(const pair<U, V>& rhs) { *this = rhs;};
            pair& operator= (const pair&rhs)
            {
                if (this != &rhs)
                {
                    this->first = rhs.first;
                    this->second = rhs.second;
                }
            }
    };
    /*
        relational operators
    */
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }
    /*
        make_pair function
    */
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y));
    }
    /*
        Node class
    */

    template <typename T>
    class Node
    {

        public:
            typedef T value_type;
            T _data;
            Node *_left;
            Node *_right;
            Node *_parent;
            Node(T data):_data(data), _left(NULL), _right(NULL),_parent(NULL){}
            Node(T data, Node* left, Node* right, Node* parent): _data(data), _left(left),_right(right), _parent(parent){};
    };
    /*
        iterators
    */
    template <class T>
    class MapIterator
    {
            public:
                typedef std::bidirectional_iterator_tag iterator_category;
                typedef std::ptrdiff_t difference_type;
                typedef T value_type;
                typedef value_type* pointer;
                typedef value_type& reference;

                MapIterator():_ptr(NULL){};
                MapIterator(pointer ptr): _ptr(ptr){}
                pointer operator->() const { return (_ptr->_data);};
                bool operator !=(const MapIterator& rhs) const { return (_ptr != rhs._ptr);}
                MapIterator operator++(int)
                {
                    MapIterator tmp(*this);
                    ++*this;
                    return(tmp);
                }
                MapIterator&  operator++() 
                {
                    pointer tmp;

                    if (_ptr)
                    {
                        if (_ptr->_right)
                        {
                            _ptr = _ptr->_right;
                            while(_ptr->_left)
                                _ptr = _ptr->_left;
                        }
                        else
                        {
                            tmp = _ptr->_parent;
                            while( tmp != NULL && _ptr == tmp->_right)
                            {
                                _ptr = tmp;
                                tmp = tmp->_parent;
                            }
                            _ptr = tmp;
                        }
                    }
                    return (*this);
                }
                MapIterator operator--(int)
                {
                    MapIterator tmp(*this);

                    --*this;
                    return(tmp);
                }

                MapIterator& operator--()
                {
                    pointer tmp;

                    if (_ptr)
                    {
                        if (_ptr->_left)
                            _ptr = _ptr->_left;
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

                friend MapIterator operator+(const MapIterator& lhs, size_t n)
                {
                    MapIterator tmp(lhs);
                    for (size_t i = 0; i < n; i++)
                        tmp++;
                    return(tmp);
                }

                friend MapIterator operator-(const MapIterator& lhs, size_t n)
                {
                    MapIterator tmp(lhs);
                    for (size_t i = 0; i < n; i++)
                        tmp--;
                    return(tmp);
                }

                private:
                    pointer _ptr;
    };
}
#endif
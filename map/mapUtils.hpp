#ifndef MAPUTILS_HPP
#define MAPUTILS_HPP
#include <iterator>

namespace ft
{
    template <class T1, class T2>
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
            T _data;
            Node *_left;
            Node *_right;
            Node(T data):_data(data), _left(NULL), _right(NULL){}
            Node(T data, Node* left, Node* right): _data(data), _left(left),_right(right){};
    };
    /*
        iterators
    */
    template <class T, class U>
    class MapIterator
    {
            public:
                typedef std::bidirectional_iterator_tag iterator_category;
                typedef std::ptrdiff_t difference_type;
                typedef pair<T, U> value_type;
                typedef value_type* pointer;
                typedef value_type& reference;
                MapIterator():ptr(NULL){};
                MapIterator(pointer ptr): ptr(ptr){}
            private:
                pointer ptr;
    };
}
#endif
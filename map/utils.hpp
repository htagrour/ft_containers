#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
    template <typename v1>
    struct vect3
    {
        vect3(v1 value, bool isExist, bool toLeft):\
        value(value),isExist(isExist),toLeft(toLeft){};

        v1 value;
        bool isExist;
        bool toLeft;
    };

    template <typename T>
    struct Node
    {
        typedef T value_type;
        typedef Node<value_type>* pointer;

        Node(){}
        Node(T data):_data(data), _left(NULL), _right(NULL),_parent(NULL), isBlack(false){}
        Node(T data, pointer left, pointer right, pointer parent, bool isBlack): 
            _data(data), _left(left),_right(right), _parent(parent), isBlack(isBlack){};
        bool operator==(const Node &rsh) { return _data == rsh._data;}
        bool operator!=(const Node &rsh) { return _data != rsh._data;}
        value_type _data;
        pointer _left;
        pointer _right;
        pointer _parent;
        bool isBlack;
    };
    
    template <typename T1, typename T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;
        pair():first(first_type()), second(second_type()){};
        pair(const first_type& a, const second_type& b): first(a), second(b){}
        template<class U, class V>
        pair(const pair<U, V>& rhs) : first(rhs.first), second(rhs.second){};
        pair& operator= (const pair&rhs)
        {
            if (this != &rhs)
            {
                this->first = rhs.first;
                this->second = rhs.second;
            }
            return *this;
        }
    };
    /*
        relational operators
    */
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first; }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first; }

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
}
#endif
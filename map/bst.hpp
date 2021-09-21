#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <memory>
#include "utils.hpp"
#include <functional>

namespace ft
{
    template <typename T>
    struct Node
    {
        typedef T value_type;
        typedef Node<value_type>* pointer;

        Node(){}
        Node(T data):_data(data), _left(NULL), _right(NULL),_parent(NULL){}
        Node(T data, pointer left, pointer right, pointer parent): 
            _data(data), _left(left),_right(right), _parent(parent){};
        bool operator==(const Node &rsh) { return _data == rsh._data;}
        bool operator!=(const Node &rsh) { return _data != rsh._data;}
        value_type _data;
        pointer _left;
        pointer _right;
        pointer _parent;  
    };

    template<class T, class Compare , class Alloc >
    class Bst
    {
        public:
            typedef T value_type;
            typedef Node<value_type> node;
            typedef typename node::pointer pointer;
            typedef size_t size_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::template rebind<node>::other node_alloc;
            
            Bst()
            {
                _alloc = node_alloc();
                _comp = Compare();
                _size = 0;
                _head = NULL;
                _end = _alloc.allocate(1);
                // _rend = _alloc.allocate(1);
                _alloc.construct(_end, node(value_type()));
                _begin = _end;
            }

            pointer get_begin() const { return _begin;}
            pointer get_end() const { return _end;}
            pointer get_rbegin() const { return _end->_parent;}
            pointer get_rend() const { return _rend;}
            size_type get_size() const { return _size;}
            size_type get_maxSize() const { return _alloc.max_size();}

            ft::pair<pointer, bool> insert(const value_type &val)
            {
                pointer newNode;
                ft::pair<pointer, bool> res = find(val);

                if (res.second)
                    return res;
                newNode = _alloc.allocate(1);
                _alloc.construct(newNode, node(val));
                if (_size)
                {
                    newNode->_parent = res.first;
                    if(_comp(val.first, res.first->_data.first))
                    {
                        if (res.first == _begin)
                            _begin = newNode;
                        res.first->_left = newNode;
                    }
                    else
                    {
                        if (res.first->_right == _end)
                        {
                            newNode->_right = _end;
                            _end->_parent = newNode;
                        }
                        res.first->_right = newNode;
                    }
                }
                else
                {
                    _head = _begin = newNode;
                    _head->_right = _end;
                    _end->_parent = _head;
                }
                _size++;
                res.first = newNode;
                return res;
            }


            ft::pair<pointer, bool> find(const value_type& val)
            {
                pointer tmp;
                bool found = false;

                if (!_size)
                    return ft::pair<pointer, bool>(tmp, found);
                //optimize // check for extr
                if (val.first != _begin->_data.first && _comp(val.first, _begin->_data.first))
                    return ft::pair<pointer, bool>(_begin, found);
                if (val.first != _end->_parent->_data.first
                    && !_comp(val.first, _end->_parent->_data.first))
                    return ft::pair<pointer, bool>(_end->_parent, found);
                tmp = _head;
                while(tmp)
                {
                    if (val.first == tmp->_data.first)
                    {
                        found = true;
                        break;
                    }
                    if (_comp(val.first, tmp->_data.first))
                    {
                        if (tmp->_left)
                            tmp = tmp->_left;
                        else
                            break;
                    }
                    else
                    {
                        if (tmp->_right && tmp->_right != _end)
                            tmp = tmp->_right;
                        else
                            break;
                    }
                }
                return ft::pair<pointer, bool>(tmp, found);
            }

            pointer lower_bound(const value_type& val)
            {
                pointer tmp = _head;

                if (_size)
                {
                    if (!_comp(_begin->_data.first, val.first))
                        return _begin;
                    if (_comp(_end->_parent->_data.first, val.first))
                        return (_end);
                    while(tmp && tmp != _end)
                    {
                        if (!_comp(tmp->_data.first, val.first))
                        {
                            while(tmp && !_comp(tmp->_data.first, val.first))
                                tmp = tmp->_left;
                            if (tmp->_data.first == val.first || !tmp->_right)
                                return tmp;
                        }
                        tmp = tmp->_right;
                    }
                    return (tmp);
                }
                else
                    return (_end);
            }

            pointer upper_bound(const value_type& val)
            {
                pointer tmp = _head;

                if (_size)
                {
                    if (!_comp(_begin->_data.first, val.first))
                        return (_begin);
                    if (_comp(_end->_data.first, val.first))
                        return (_end);
                    while(tmp && tmp != _end)
                    {
                        if (!_comp(tmp->_data.first, val.first))
                        {
                            while((!_comp(tmp->_data.first, val.first)))
                            {
                                if (tmp->_data.first == val.first)
                                    break;
                                if (!tmp->_left)
                                    break;
                                tmp = tmp->_left;
                            }
                            std::cout << tmp->_data.first << std::end;
                            return (tmp);
                        }
                        if (!tmp->_right)
                            break;
                        tmp = tmp->_right;
                    }
                    return tmp;
                }
                else
                    return (_end);
            }

        public:
            pointer _head;
            pointer _begin;
            pointer _end;
            pointer _rend;
            size_type _size;
            node_alloc _alloc;
            Compare _comp;
    };
}
#endif

#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <memory>
#include "utils.hpp"
#include <functional>
#include "../utils/reverse_iterator.hpp"
#include "iterator.hpp"
#define SPACE 10
namespace ft
{

    template<class T, class Compare , class Alloc >
    class Bst
    {
        public:
            typedef T value_type;
            typedef Node<value_type> node_value;
            typedef node_value* pointer;
            typedef size_t size_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::template rebind<node_value>::other node_alloc;
            typedef ft::iterator<value_type, node_value> iterator;
            typedef ft::iterator<const value_type, node_value > const_iterator;
            typedef ft::reverseIterator<iterator> reverse_iterator;
            typedef ft::reverseIterator<const_iterator> const_reverse_iterator;
            
            Bst()
            {
                _alloc = node_alloc();
                _comp = Compare();
                refresh();
            }
            ~Bst()
            {
                clear();
                // deallocate_node(_end);
            }
            iterator get_begin() { return iterator(_begin);}
            const_iterator get_begin() const { return iterator(_begin);}
            iterator get_end()  { return iterator(_end);}
            const_iterator get_end() const { return iterator(_end);}

            // reverse_iterator get_rbegin() const { return _end->_parent;}
            // reverse_iterator get_rend() const { return NULL;}
            size_type get_size() const { return _size;}
            size_type get_maxSize() const { return _alloc.max_size();}

            pair<pointer, bool> insert(const value_type& val)
            {
                pair<pointer, bool> res;

                if (_size)
                {
                    res = insertToLeaf(val);
                    if (res.second)
                        fixViolation(res.first);
                    return (res);
                }
                else
                    return (pair<pointer, bool> (insertToHead(val), true));
            }
                        
            pointer find(const value_type& val) const
            {
                vect3<pointer> res = findHelper(_head, val);

                if (res.isExist)
                    return res.value;
                return (_end);
            };

            pointer Bound(const value_type& val) const
            {
                return (BoundHelper(_head, _head,val));
            }

            void clear()
            {
                clearHelper(_head);
                _size = 0;
            }

            void print(){print2DUtil(_head, 0);}


    private:

        void clearHelper(pointer node)
        {
            if (node && node != _end)
            {
                clearHelper(node->_left);
                clearHelper(node->_right);

                deallocate_node(node);
                node = NULL; 
            }
        }

        pointer BoundHelper(pointer node, pointer prev,const value_type& val) const
        {
            if (_comp(val.first,_begin->_data.first))
                return _begin;
            if (_comp( _end->_parent->_data.first,val.first))
                return _end;
            if (node->_data.first == val.first)
                return node;
            if (_comp(val.first,node->_data.first))
            {
                prev = node;
                if (node->_left)
                    return BoundHelper(node->_left, prev, val);
            }
            else
            {
                if (node->_right && node->_right != _end)
                    return (BoundHelper(node->_right, prev, val));
            }
            return prev;
        }

        void fixViolation(pointer node)
        {
            pointer parent;
            pointer grandParent;

            if (node == _head || node->isBlack || node->_parent->isBlack)
            {
                _head->isBlack = true;
                return;
            }

            parent = node->_parent;
            grandParent = parent->_parent;
            if (parent == grandParent->_left)
                LeftChild(node, parent, grandParent);
            else
                RightChild(node, parent, grandParent);
            fixViolation(node);
        }

        void LeftChild(pointer &node, pointer parent, pointer gParent)
        {
            pointer uncle = gParent->_right;

            //color correction:
            if (uncle && !uncle->isBlack)
                colorCorr(node, parent, gParent, uncle);
            else
            {
                //Left Right Rotation
                if (node == parent->_right)
                {
                    rotateLeft(parent);
                    node  = parent;
                    parent  = node->_parent;
                }
                rotateRight(gParent);
                std::swap(parent->isBlack, gParent->isBlack);
                node = parent;
            }

        }

        void RightChild(pointer &node, pointer parent, pointer gParent)
        {
            pointer uncle = gParent->_left;

            if (uncle && !uncle->isBlack)
                colorCorr(node, parent, gParent,uncle);
            else
            {
                if (node == parent->_left)
                {
                    rotateRight(parent);
                    node = parent;
                    parent = node->_parent;
                }
                rotateLeft(gParent);
                std::swap(parent->isBlack, gParent->isBlack);
                node = parent;
            }
        }

        void colorCorr(pointer &node, pointer parent, pointer gParent,pointer uncle)
        {
            gParent->isBlack = false;
            parent->isBlack = true;
            uncle->isBlack = true;
            node = gParent;
        }

        void rotateRight(pointer node)
        {
            pointer left = node->_left;
            
            node->_left = left->_right;
            if (node->_left)
                node->_left->_parent = node;
            left->_parent = node->_parent;
            if (!left->_parent)
                _head = left;
            else if (node == node->_parent->_left)
                node->_parent->_left = left;
            else
                node->_parent->_right = left;
            left->_right = node;
            node->_parent = left;
        }

        void rotateLeft(pointer node)
        {
            pointer right = node->_right;

            node->_right = right->_left;
            if (node->_right)
                node->_right->_parent = node;
            right->_parent = node->_parent;
            if(!node->_parent)
                _head = right;
            else
                if (node == node->_parent->_left)
                    node->_parent->_left = right;
            else
                node->_parent->_right = right;
            right->_left = node;
            node->_parent = right;
        }

        pointer Uncle(pointer node)
        {
            pointer parent = node->_parent;
            pointer grandParent = parent->_parent;
            return ((parent->_left == node) ? grandParent->_right: grandParent->_left);
        }

        pair<pointer, bool> insertToLeaf(const value_type& val)
        {
            vect3<pointer> result = findHelper(_head,val);
            pointer newNode;
            if (result.isExist)
                return (pair<pointer, bool>(result.value, false));
            if (result.value == _end)
                result.value = _end->_parent;
            newNode = allocate_node(val);
            newNode->_parent = result.value;
            if (result.toLeft)
            {
                result.value->_left = newNode;
                _begin = (result.value == _begin) ? newNode : _begin;
            }
            else
            {
                if (result.value->_right == _end)
                {
                    _end->_parent = newNode;
                    newNode->_right = _end;
                }
                result.value->_right = newNode;
            }
            _size++;
            return pair<pointer, bool>(newNode, true);
        }

        pointer insertToHead(const value_type& val)
        {
            _head = allocate_node(val);
            _head->isBlack = true;
            _head->_right = _end;
            _end->_parent = _head;
            _begin = _head;
            _size++;
            return _head;
        }

        vect3<pointer> findHelper(pointer tmp,const value_type& val) const
        {
            if (!_size)
                return vect3<pointer>(NULL, false,false);
            if (_begin->_data.first != val.first && _comp( val.first, _begin->_data.first))
                return vect3<pointer>(_begin, false, true);
            if (_end->_parent->_data != val && !_comp(val.first, _end->_parent->_data.first))
                return vect3<pointer>(_end, false, false);
            if (tmp->_data.first == val.first)
                return vect3<pointer>(tmp, true, false);
            if (_comp(val.first, tmp->_data.first))
            {
                if (tmp->_left)
                    return findHelper(tmp->_left, val);
                else
                    return vect3<pointer>(tmp, false, true);
            }
            else
            {
                if (tmp->_right && tmp->_right != _end)
                    return findHelper(tmp->_right, val);
                else
                    return vect3<pointer>(tmp, false, false);
            }
        }
        void print2DUtil(pointer root, int space)
        {
            // Base case
            if (root == NULL)
                return;
        
            // Increase distance between levels
            space += SPACE;
        
            // Process right child first
            print2DUtil(root->_right, space);
        
            // Print current node after space
            // count
            std::cout<<std::endl;
            for (int i = SPACE; i < space; i++)
                std::cout<<" ";
            std::cout<<root->_data.first<<"\n";
        
            // Process left child
            print2DUtil(root->_left, space);
        }
 
        void traversTree(pointer node)
        {
            if (!node || node == _end)
                return;
            std::cout << node->_data << std::endl;
            if (node->_right)
                traversTree(node->_right);
            else
            {
                if (node == node->_parent->_right)
                    traversTree(node->_parent->_parent);
                else
                    traversTree(node->_parent);
            }
        }

        pointer allocate_node(const value_type& val)
        {
            pointer newNode = _alloc.allocate(1);
            _alloc.construct(newNode, Node<value_type>(val));
            return newNode;
        }

        void deallocate_node(pointer node)
        {
            _alloc.destroy(node);
            _alloc.deallocate(node, 1);
        }
        void refresh()
        {
            _head = NULL;
            _end = allocate_node(value_type());
            _begin = _end;
            _size = 0;
        }
        private:
            pointer _head;
            pointer _begin;
            pointer _end;
            size_type _size;
            node_alloc _alloc;
            Compare _comp;
    };
}
#endif

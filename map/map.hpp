#ifndef MAP_HPP
#define MAP_HPP

#include "mapUtils.hpp"
namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>,
              class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const key_type, T> value_type;
            typedef ft::Node<value_type> node;
            typedef Compare key_compare;
            // typedef ###### value_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;
            typedef ft::MapIterator <node> iterator;
            // typedef ft::ConstVectIterator<value_type> const_iterator;
            // typedef ft::RevereVectIterator<value_type> reverse_iterator;
            // typedef ft::ConstRevereVectIterator<value_type> const_reverse_iterator;

            explicit map(const key_compare& comp = key_compare(),
                         const allocator_type &alloc = allocator_type()): _comp(comp), _alloc(alloc)
                        {
                            _root = _begin = NULL;
                            _size = 0;
                        }
            template <typename InputIterator>
            map(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc)
                {
                    _root = _begin = NULL;
                    _size = 0;
                }
            map(const map& rhs)
            {
                _root = NULL;
                //*this = rhs
            }
            iterator begin() const { return(iterator(_begin));}
            iterator end() const { return (iterator(NULL));}
            void insert(value_type data)
            {
                node *new_node = new node(data);
                if (!_root)
                {
                    _root = new_node;
                    _begin = new_node;
                }
                else
                {
                    node *p = _root;

                    while(p)
                    {
                        if (data > p->_data)
                        {
                            if (!p->_right)
                                break;
                            else
                                p = p->_right;
                        }
                        else
                        {
                            if (!p->_left)
                                break;
                            else
                                p = p->_left;   
                        }
                    }
                    new_node->_parent = p;
                    if (data > p->_data)
                    {
                        p->_right = new_node;
                    }
                    else
                        p->_left = new_node;
                    if (!_begin || data < _begin->_data)
                        _begin = new_node;
                }
                _size += 1;
            }
            size_type size() const { return (_size);};
        private:
            node *_root;
            key_compare _comp;
            allocator_type _alloc;
            size_type _size;
            node *_begin;
    };
}
#endif
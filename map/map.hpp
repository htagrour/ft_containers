#ifndef MAP_HPP
#define MAP_HPP
#include "bst.hpp"
#include "iterator.hpp"
#include <iostream>
#include "../utils/reverse_iterator.hpp"
namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>,
              class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const key_type, mapped_type> value_type;
            typedef ft::Node<value_type> node;
            typedef typename node::pointer node_pointer;
            typedef Compare key_compare;
            // typedef ###### value_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;
            typedef ft::Bst<value_type, key_compare, allocator_type> bst;
            typedef ft::iterator<node> iterator;
            typedef ft::iterator<const node> const_iterator;
            typedef ft::reverseIterator<iterator> reverse_iterator;
            typedef ft::reverseIterator<const_iterator> const_reverse_iterator;

            explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
              {
                  _bst = bst();
                  _alloc = alloc;
                  _comp = comp;
              }
            
            // Iterartors
            iterator begin() { return iterator(_bst.get_begin());}
            const_iterator begin() const {return const_iterator(_bst.get_begin());}

            iterator end() { return iterator(_bst.get_end());}
            const_iterator end() const {return const_iterator(_bst.get_end());}

            reverse_iterator rbegin() { return reverse_iterator(_bst.get_rbegin());}
            const_reverse_iterator rbegin() const {return const_reverse_iterator(_bst.get_rbegin());}

            reverse_iterator rend() { return reverse_iterator(_bst.get_rend());}
            const_reverse_iterator rend() const {return const_iterator(_bst.get_rend());}

            // Capacity
            size_type size() const { return _bst.get_size();}
            size_type max_size() const { return _bst.get_maxSize();}
            bool empty() const { return !size();}

            // Modifiers
            // std::pair<iterator,bool> insert (const value_type& val)
            // {
            //     std::pair <node*,bool> result = _bst.insert(val); 
            //     return (std::make_pair<iterator, bool>(result.first, result.second));
            // }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    insert(*first);            
                    first++;
                }
            }
            std::pair<iterator, bool> insert(const value_type& k)
            {
                std::pair<node_pointer, bool> res = _bst.insert(k);
                return std::pair<iterator, bool>(iterator(res.first), !res.second);
            }

            iterator find(const key_type &k)
            {
                std::pair<key_type, mapped_type> _pair(k, mapped_type());
                std::pair<node_pointer,bool> res = _bst.find(_pair);

                if (res.second)
                    return iterator(res.first);
                return (end());
            }

            const_iterator find(const key_type& k) const
            {
                std::pair<key_type, mapped_type> _pair(k, mapped_type());
                std::pair<node_pointer,bool> res = _bst.find(_pair);

                if (res.second)
                    return const_iterator(res.first);
                return (end());
            }

            size_type count (const key_type& k)
            { 
                if (find(k) == end())
                    return 0;
                return 1;
            }

        private:
            bst _bst;
            key_compare _comp;
            allocator_type _alloc;

    };
}
#endif
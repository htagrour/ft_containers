#ifndef LIST_HPP
#define LIST_HPP

#include <memory>
typedef struct t_node
{
    void *data;
    struct t_node *next;
    struct t_node *prev;
} Node;

namespace ft
{
    template<typename T, typename Alloc = std::allocator<T> >
    class list
    {
        private:
            Node* head;
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename std::iterator<std::bidirectional_iterator_tag , value_type> iterator;
            typedef  const_iterator;
            typedef implementation-defined size_type;
            typedef implementation-defined difference_type;
            typedef reverse_iterator<iterator> reverse_iterator;
            typedef reverse_iterator<const_iterator> const_reverse_iter

    };

}

#endif

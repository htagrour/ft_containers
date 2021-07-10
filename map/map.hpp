#ifndef MAP_HPP
#define MAP_HPP
namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>,
              class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const Key, T> value_type;
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
            // typedef ft::VectIterator <value_type> iterator;
            // typedef ft::ConstVectIterator<value_type> const_iterator;
            // typedef ft::RevereVectIterator<value_type> reverse_iterator;
            // typedef ft::ConstRevereVectIterator<value_type> const_reverse_iterator;

            explicit map(const key_compare& comp = key_compare(),
                         const allocator_type &alloc = allocator_type()): _comp(comp), _alloc(alloc)
                        {
                            _root = NULL;
                            _size = 0;
                        }
            template <InputIterator first>
            map(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()):_comp(comp), _alloc(alloc)
                {
                    _root = NULL;
                    _size = 0;
                }
            map(const map& rhs)
            {
                _root = NULL;
                //*this = rhs
            }
        private:
            node *_root;
            key_compare _comp;
            allocator_type _alloc;
            size_type _size;
    }
}
#endif
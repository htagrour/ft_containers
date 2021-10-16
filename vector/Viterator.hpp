#ifndef VITERATOR_HPP
#define VITERATOR_HPP
namespace ft
{    
    template <typename T>
    class Iterator
    {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
            
            Iterator():_ptr(NULL){};
            Iterator(pointer _ptr): _ptr(_ptr){}
            Iterator(const Iterator &rsh){*this = rsh;}
            Iterator &operator=(const Iterator<T> &rsh)
            {
                if (this != &rsh)
                    this->_ptr = rsh._ptr;
                return (*this);
            }
            reference operator*() const { return *_ptr; }
            pointer operator->() { return _ptr; }
            reference operator[](difference_type rhs) const {return _ptr[rhs];}
            Iterator& operator++() { _ptr++; return *this; }  
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            Iterator& operator--() { _ptr--; return *this; }  
            Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
            difference_type operator-(const Iterator& rhs) {return _ptr - rhs._ptr;}
            Iterator operator-(difference_type n) {return _ptr - n;}
            operator Iterator<const T>() const {return (Iterator<const T>(this->_ptr));}
            pointer base() const {  return (_ptr);};
            ~Iterator(){}
        protected:
            pointer _ptr;
    };
    
    /*
        Operators 
    */

    template<typename T>
    bool operator== (const Iterator<T>& a, const Iterator<T>& b) { return a.base() == b.base(); };

    template<typename T, typename U>
    bool operator== (const Iterator<T>& a, const Iterator<U>& b) { return a.base() == b.base(); };

    template<typename T>
    bool operator!= (const Iterator<T>& a, const Iterator<T>& b) { return a.base() != b.base(); };

    template<typename T, typename U>
    bool operator!= (const Iterator<T>& a, const Iterator<U>& b) { return a.base() != b.base(); };

    template<typename T>
    bool operator> (const Iterator<T>& a, const Iterator<T>& b) { return a.base() > b.base(); };

    template<typename T, typename U>
    bool operator> (const Iterator<T>& a, const Iterator<U>& b) { return a.base() > b.base(); };

    template<typename T>
    bool operator>= (const Iterator<T>& a, const Iterator<T>& b) { return a.base() >= b.base(); };

    template<typename T, typename U>
    bool operator>= (const Iterator<T>& a, const Iterator<U>& b) { return a.base() >= b.base(); };

    template<typename T>
    bool operator< (const Iterator<T>& a, const Iterator<T>& b) { return a.base() < b.base(); };

    template<typename T, typename U>
    bool operator< (const Iterator<T>& a, const Iterator<U>& b) { return a.base() < b.base(); };

    template<typename T>
    bool operator<= (const Iterator<T>& a, const Iterator<T>& b) { return a.base() <= b.base(); };

    template<typename T, typename U>
    bool operator<= (const Iterator<T>& a, const Iterator<U>& b) { return a.base() <= b.base(); };

    template<typename T>
    Iterator<T> operator+(typename Iterator<T>::difference_type n,
                            const Iterator<T> &rsh)
            {return(rsh.base() + n);}
    
        template<typename T>
    Iterator<T> operator+( const Iterator<T> &lsh,
            typename Iterator<T>::difference_type n)
            {return(lsh.base() + n);}
}
#endif
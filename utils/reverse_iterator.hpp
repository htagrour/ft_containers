#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
namespace ft
{
        //REVERSE ITERTOR
    template <typename Iterator>
    class reverseIterator: public Iterator
    {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::ptrdiff_t difference_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;

            reverseIterator():Iterator(NULL){};
            reverseIterator(Iterator ptr): Iterator(ptr){};
            template <typename Iter>
            reverseIterator(const reverseIterator<Iter> &rsh) { this->ptr = rsh.base();}
            reverseIterator& operator++() {Iterator::operator--(); return (*this);}  
            reverseIterator operator++(int) { return(Iterator::operator--(0)); }
            reverseIterator& operator--() { Iterator::operator++(); return (*this);}  
            reverseIterator operator--(int) { return (Iterator::operator++(0)); }
            Iterator base() const { return (*this);}
    };

    template <typename T>
    bool operator==(const reverseIterator<T>& rsh, const reverseIterator<T> &lsh)
    {return (rsh.base() == lsh.base());}

    template<typename T, typename U>
    bool operator== (const reverseIterator<T> &rsh, const reverseIterator<U> &lsh)
    {return (rsh.base() == lsh.base());}

    template <typename T>
    bool operator!=(const reverseIterator<T>& rsh, const reverseIterator<T> &lsh)
    {return (rsh.base() != lsh.base());}

    template<typename T, typename U>
    bool operator!= (const reverseIterator<T> &rsh, const reverseIterator<U> &lsh)
    {return (rsh.base() != lsh.base());}
    template<typename T>
    bool operator> (const reverseIterator<T>& a, const reverseIterator<T>& b) { return a.base() < b.base(); };

    template<typename T, typename U>
    bool operator> (const reverseIterator<T>& a, const reverseIterator<U>& b) { return a.base() < b.base(); };

    template<typename T>
    bool operator>= (const reverseIterator<T>& a, const reverseIterator<T>& b) { return a.base() <= b.base(); };

    template<typename T, typename U>
    bool operator>= (const reverseIterator<T>& a, const reverseIterator<U>& b) { return a.base() <= b.base(); };

    template<typename T>
    bool operator< (const reverseIterator<T>& a, const reverseIterator<T>& b) { return a.base() > b.base(); };

    template<typename T, typename U>
    bool operator< (const reverseIterator<T>& a, const reverseIterator<U>& b) { return a.base() > b.base(); };

    template<typename T>
    bool operator<= (const reverseIterator<T>& a, const reverseIterator<T>& b) { return a.base() >= b.base(); };

    template<typename T, typename U>
    bool operator<= (const reverseIterator<T>& a, const reverseIterator<U>& b) { return a.base() >= b.base(); };

    template<typename T>
    reverseIterator<T> operator+(typename reverseIterator<T>::difference_type n,
                            const reverseIterator<T> &rsh)
            {return(rsh.base() - n);}
    
    template<typename T>
    reverseIterator<T> operator+( const reverseIterator<T> &lsh,
            typename reverseIterator<T>::difference_type n)
            {return(lsh.base() - n);}

    template<typename T>
    reverseIterator<T> operator-( const reverseIterator<T> &lsh,
            typename reverseIterator<T>::difference_type n)
            {return(lsh.base() + n);}
    template<typename T>
    typename reverseIterator<T>::difference_type operator-(const reverseIterator<T> &lsh,
                            const reverseIterator<T> &rsh)
            {return(rsh.base() - lsh.base());}
    template<typename T, typename U>
    typename reverseIterator<T>::difference_type operator-(const reverseIterator<T> &lsh,
                            const reverseIterator<U> &rsh)
            {return(rsh.base() - lsh.base());}
}
#endif
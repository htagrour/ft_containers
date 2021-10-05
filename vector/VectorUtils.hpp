#ifndef VECTORUTILS_HPP
#define VECTORUTILS_HPP
#include <iterator>
namespace ft
{    
    template <typename T>
    class VectIterator
    {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef value_type* pointer;
            typedef value_type& reference;
            
            VectIterator():_ptr(NULL){};
            VectIterator(pointer _ptr): _ptr(_ptr){}
            VectIterator(const VectIterator &rsh){*this = rsh;}
            VectIterator &operator=(const VectIterator<T> &rsh)
            {
                if (this != &rsh)
                    this->_ptr = rsh._ptr;
                return (*this);
            }
            reference operator*() const { return *_ptr; }
            pointer operator->() { return _ptr; }
            reference operator[](difference_type rhs) const {return _ptr[rhs];}
            VectIterator& operator++() { _ptr++; return *this; }  
            VectIterator operator++(int) { VectIterator tmp = *this; ++(*this); return tmp; }
            VectIterator& operator--() { _ptr--; return *this; }  
            VectIterator operator--(int) { VectIterator tmp = *this; --(*this); return tmp; }
            difference_type operator-(const VectIterator& rhs) {return _ptr - rhs._ptr;}
            VectIterator operator-(difference_type n) {return _ptr - n;}
            operator VectIterator<const T>() const {return (VectIterator<const T>(this->_ptr));}
            pointer base() const {  return (_ptr);};

        protected:
            pointer _ptr;
    };
    
    /*
        Operators 
    */

    template<typename T>
    bool operator== (const VectIterator<T>& a, const VectIterator<T>& b) { return a.base() == b.base(); };

    template<typename T, typename U>
    bool operator== (const VectIterator<T>& a, const VectIterator<U>& b) { return a.base() == b.base(); };

    template<typename T>
    bool operator!= (const VectIterator<T>& a, const VectIterator<T>& b) { return a.base() != b.base(); };

    template<typename T, typename U>
    bool operator!= (const VectIterator<T>& a, const VectIterator<U>& b) { return a.base() != b.base(); };

    template<typename T>
    bool operator> (const VectIterator<T>& a, const VectIterator<T>& b) { return a.base() > b.base(); };

    template<typename T, typename U>
    bool operator> (const VectIterator<T>& a, const VectIterator<U>& b) { return a.base() > b.base(); };

    template<typename T>
    bool operator>= (const VectIterator<T>& a, const VectIterator<T>& b) { return a.base() >= b.base(); };

    template<typename T, typename U>
    bool operator>= (const VectIterator<T>& a, const VectIterator<U>& b) { return a.base() >= b.base(); };

    template<typename T>
    bool operator< (const VectIterator<T>& a, const VectIterator<T>& b) { return a.base() < b.base(); };

    template<typename T, typename U>
    bool operator< (const VectIterator<T>& a, const VectIterator<U>& b) { return a.base() < b.base(); };

    template<typename T>
    bool operator<= (const VectIterator<T>& a, const VectIterator<T>& b) { return a.base() <= b.base(); };

    template<typename T, typename U>
    bool operator<= (const VectIterator<T>& a, const VectIterator<U>& b) { return a.base() <= b.base(); };

    template<typename T>
    VectIterator<T> operator+(typename VectIterator<T>::difference_type n,
                            const VectIterator<T> &rsh)
            {return(rsh.base() + n);}
    
        template<typename T>
    VectIterator<T> operator+( const VectIterator<T> &lsh,
            typename VectIterator<T>::difference_type n)
            {return(lsh.base() + n);}
}
#endif
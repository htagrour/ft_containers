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
            
            VectIterator():ptr(NULL){};
            VectIterator(pointer ptr): ptr(ptr){}
            VectIterator(const VectIterator &rsh){*this = rsh;}
            VectIterator &operator=(const VectIterator<T> &rsh)
            {
                if (this != &rsh)
                    this->ptr = rsh.ptr;
                return (*this);
            }
            reference operator*() const { return *ptr; }
            pointer operator->() { return ptr; }
            reference operator[](difference_type rhs) const {return ptr[rhs];}
            VectIterator& operator++() { ptr++; return *this; }  
            VectIterator operator++(int) { VectIterator tmp = *this; ++(*this); return tmp; }
            VectIterator& operator--() { ptr--; return *this; }  
            VectIterator operator--(int) { VectIterator tmp = *this; --(*this); return tmp; }
            difference_type operator-(const VectIterator& rhs) {return ptr - rhs.ptr;}
            VectIterator operator-(difference_type n) {return ptr - n;}
            operator VectIterator<const T>() const {return (VectIterator<const T>(this->ptr));}
            pointer base() const {  return (ptr);};

        protected:
            pointer ptr;
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
    
    template <typename Iterator>
    class RevereVectIterator
    {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::ptrdiff_t difference_type;
            typedef typename Iterator::value_type value_type;
            typedef value_type* pointer;
            typedef value_type& reference;

            RevereVectIterator(): ptr(NULL){};
            RevereVectIterator(Iterator ptr): ptr(ptr){};
            template <typename Iter>
            RevereVectIterator(const RevereVectIterator<Iter> &rsh) { this->ptr = rsh.base();}
            // RevereVectIterator& operator=(const RevereVectIterator &rsh)
            // {
            //     if (this != &rsh)
            //         ptr = rsh.ptr;
            //     return (*this);
            // }
            RevereVectIterator& operator++() { --this->ptr; return (*this);}  
            RevereVectIterator operator++(int) { RevereVectIterator tmp = *this; --(this->ptr); return tmp; }
            RevereVectIterator& operator--() { ++this->ptr; return (*this);}  
            RevereVectIterator operator--(int) { RevereVectIterator tmp = *this; ++this->ptr; return tmp; }
            reference operator*() const { return *ptr; }
            reference operator[](difference_type rhs) const {return ptr[-rhs];}
            Iterator base() const { return (ptr);}
        private:
            Iterator ptr;

    };

    template <typename T>
    bool operator==(const RevereVectIterator<T>& rsh, const RevereVectIterator<T> &lsh)
    {return (rsh.base() == lsh.base());}

    template<typename T, typename U>
    bool operator== (const RevereVectIterator<T> &rsh, const RevereVectIterator<U> &lsh)
    {return (rsh.base() == lsh.base());}

    template <typename T>
    bool operator!=(const RevereVectIterator<T>& rsh, const RevereVectIterator<T> &lsh)
    {return (rsh.base() != lsh.base());}

    template<typename T, typename U>
    bool operator!= (const RevereVectIterator<T> &rsh, const RevereVectIterator<U> &lsh)
    {return (rsh.base() != lsh.base());}
    template<typename T>
    bool operator> (const RevereVectIterator<T>& a, const RevereVectIterator<T>& b) { return a.base() < b.base(); };

    template<typename T, typename U>
    bool operator> (const RevereVectIterator<T>& a, const RevereVectIterator<U>& b) { return a.base() < b.base(); };

    template<typename T>
    bool operator>= (const RevereVectIterator<T>& a, const RevereVectIterator<T>& b) { return a.base() <= b.base(); };

    template<typename T, typename U>
    bool operator>= (const RevereVectIterator<T>& a, const RevereVectIterator<U>& b) { return a.base() <= b.base(); };

    template<typename T>
    bool operator< (const RevereVectIterator<T>& a, const RevereVectIterator<T>& b) { return a.base() > b.base(); };

    template<typename T, typename U>
    bool operator< (const RevereVectIterator<T>& a, const RevereVectIterator<U>& b) { return a.base() > b.base(); };

    template<typename T>
    bool operator<= (const RevereVectIterator<T>& a, const RevereVectIterator<T>& b) { return a.base() >= b.base(); };

    template<typename T, typename U>
    bool operator<= (const RevereVectIterator<T>& a, const RevereVectIterator<U>& b) { return a.base() >= b.base(); };

    template<typename T>
    RevereVectIterator<T> operator+(typename RevereVectIterator<T>::difference_type n,
                            const RevereVectIterator<T> &rsh)
            {return(rsh.base() - n);}
    
    template<typename T>
    RevereVectIterator<T> operator+( const RevereVectIterator<T> &lsh,
            typename RevereVectIterator<T>::difference_type n)
            {return(lsh.base() - n);}

    template<typename T>
    RevereVectIterator<T> operator-( const RevereVectIterator<T> &lsh,
            typename RevereVectIterator<T>::difference_type n)
            {return(lsh.base() + n);}
    template<typename T>
    typename RevereVectIterator<T>::difference_type operator-(const RevereVectIterator<T> &lsh,
                            const RevereVectIterator<T> &rsh)
            {return(rsh.base() - lsh.base());}
    template<typename T, typename U>
    typename RevereVectIterator<T>::difference_type operator-(const RevereVectIterator<T> &lsh,
                            const RevereVectIterator<U> &rsh)
            {return(rsh.base() - lsh.base());}
}
#endif
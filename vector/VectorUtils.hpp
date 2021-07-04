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

            VectIterator(pointer ptr): ptr(ptr){}
            reference operator*() const { return *ptr; }
            pointer operator->() { return ptr; }
            reference operator[](difference_type rhs) const {return ptr[rhs];}
            VectIterator& operator++() { ptr++; return *this; }  
            VectIterator operator++(int) { VectIterator tmp = *this; ++(*this); return tmp; }
            VectIterator& operator--() { ptr--; return *this; }  
            VectIterator operator--(int) { VectIterator tmp = *this; --(*this); return tmp; }
            difference_type operator-(const VectIterator& rhs) {return ptr - rhs.ptr;}
            friend bool operator== (const VectIterator& a, const VectIterator& b) { return a.ptr == b.ptr; };
            friend bool operator!= (const VectIterator& a, const VectIterator& b) { return a.ptr != b.ptr; };
            friend VectIterator operator+(const VectIterator&a , size_t n) { return VectIterator(a.ptr + n);};

        protected:
            pointer ptr;
    };

    template <typename T>
    class ConstVectIterator
    {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef value_type* pointer;
            typedef const value_type& reference;

            ConstVectIterator(pointer ptr): ptr(ptr){}
            reference operator*() const { return *ptr; }
            pointer operator->() { return ptr; }
            reference operator[](difference_type rhs) const {return ptr[rhs];}
            ConstVectIterator& operator++() { ptr++; return *this; }  
            ConstVectIterator operator++(int) { ConstVectIterator tmp = *this; ++(*this); return tmp; }
            ConstVectIterator& operator--() { ptr--; return *this; }  
            ConstVectIterator operator--(int) { ConstVectIterator tmp = *this; --(*this); return tmp; }
            difference_type operator-(const ConstVectIterator& rhs) {return ptr - rhs.ptr;}
            friend bool operator== (const ConstVectIterator& a, const ConstVectIterator& b) { return a.ptr == b.ptr; };
            friend bool operator!= (const ConstVectIterator& a, const ConstVectIterator& b) { return a.ptr != b.ptr; }; 

        protected:
            pointer ptr;
    };

    template <typename T>
    class RevereVectIterator: public VectIterator<T>
    {
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef std::ptrdiff_t difference_type;
            typedef T value_type;
            typedef value_type* pointer;
            typedef value_type& reference;

            RevereVectIterator(pointer ptr): VectIterator<T>::VectIterator(ptr){};
            RevereVectIterator& operator++() { --this->ptr; return (*this);}  
            RevereVectIterator operator++(int) { RevereVectIterator tmp = *this; --(*this); return tmp; }
            RevereVectIterator& operator--() { --this->ptr; return (*this);}  
            RevereVectIterator operator--(int) { RevereVectIterator tmp = *this; ++(*this); return tmp; }
    };
    
}
#endif
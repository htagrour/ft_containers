#ifndef VECTORUTILS_HPP
#define VECTORUTILS_HPP
#include <iterator>
namespace ft
{
    template <class T>
    struct iterator_traits {
        typedef typename T::value_type            value_type;
        typedef typename T::difference_type       difference_type;
        typedef typename T::iterator_category     iterator_category;
        typedef typename T::pointer               pointer;
        typedef typename T::reference             reference;
    };

    template<typename T>
    struct iterator_traits<T*>
    {
        typedef  std::random_access_iterator_tag iterator_category;
        typedef  T value_type;
        typedef  ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
    };

    template<typename T>
    struct iterator_traits<const T*>
    {
        typedef  std::random_access_iterator_tag  iterator_category;
        typedef  T value_type;
        typedef  ptrdiff_t difference_type;
        typedef const T* pointer;
        typedef const T& reference;
    };
    
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
            friend bool operator== (const VectIterator& a, const VectIterator& b) { return a.ptr == b.ptr; };
            friend bool operator!= (const VectIterator& a, const VectIterator& b) { return a.ptr != b.ptr; }; 

        protected:
            pointer ptr;
    };

    // template <typename T>
    // class ConstVectIterator
    // {
    //     public:
    //         typedef std::random_access_iterator_tag iterator_category;
    //         typedef std::ptrdiff_t difference_type;
    //         typedef T value_type;
    //         typedef value_type* pointer;
    //         typedef value_type& reference;

    //         VectIterator(pointer ptr): ptr(ptr){}
    //         reference operator*() const { return *ptr; }
    //         pointer operator->() { return ptr; }
    //         reference operator[](difference_type rhs) const {return ptr[rhs];}
    //         VectIterator& operator++() { ptr++; return *this; }  
    //         VectIterator operator++(int) { VectIterator tmp = *this; ++(*this); return tmp; }
    //         VectIterator& operator--() { ptr--; return *this; }  
    //         VectIterator operator--(int) { VectIterator tmp = *this; --(*this); return tmp; }
    //         friend bool operator== (const VectIterator& a, const VectIterator& b) { return a.ptr == b.ptr; };
    //         friend bool operator!= (const VectIterator& a, const VectIterator& b) { return a.ptr != b.ptr; }; 

    //     protected:
    //         pointer ptr;
    // };

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
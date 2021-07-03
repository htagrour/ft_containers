#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{
    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };

    template <typename T>
    struct is_integral
    {
        static const bool value = false;
    };

    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<short int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned short int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long int>
    {
        static const bool value = true;
    };

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
}
#endif
#include <exception>
#include <iostream>
// allocators >>
#include "list/ListUtils.hpp"
#include "list/List.hpp"
#include <memory>
#include <list>
#include <type_traits>

template <typename T>
struct is_floating_point
{
    static const bool value = false;
};

template <>
struct is_floating_point<float> {
    static const bool value = true;
};


// template< typename T, std::enable_if<!std::is_floating_point<T>::value, bool> = true >
// void fun(T t)
// {
//     std::cout << "It's not a float" << std::endl;
// }

#include <iostream>
using namespace std;
 
template <class T>
void fun(T a, T b)
{
   cout << "The main template fun(): "
        << a << endl;
}
 
template<int, unsigned int>
void fun(int a,  unsigned int b)
{
    cout << "Specialized Template for int type: "
         << a << endl;
}
 
int main()
{
    fun('a', 'b');
    fun(10, 10);
    fun(10.14, 10.5);
}

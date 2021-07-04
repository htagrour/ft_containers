#include <exception>
#include <iostream>
// allocators >>
#include "list/ListUtils.hpp"
// #include "list/List.hpp"
#include <memory>
#include <list>
#include <type_traits>
#include "vector/vector.hpp"
#include <vector>
#include <typeinfo>
class Test
{
    public:
        Test(int i):_data(i){ std::cout << "Const called\n";}
        ~Test(){std::cout << "Destr called\n"; _data = 0;};
        int _data;
};
template<typename T>
void print_shit(T container)
{
    for (typename T::iterator it = container.begin(); it != container.end();it++)
        std::cout << *it << std::endl;
}
int main()
{
    ft::vector<int> vect;
    std::vector<int> f(12,2);
    try
    {
        for (int i = 0; i < 10; i++)
            vect.push_back(i);
        vect.insert(vect.begin() + 2, f.begin(),f.end());
        // std::cout << vect;
        print_shit<ft::vector<int> >(vect);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return (0);
}

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
    {
        ft::vector<int> vect;
        ft::vector<int> f(0,100000);
        int *p;

        try
        {
            for (int i = 0; i < 100000; i++)
                vect.push_back(i);
            std::cout << (vect <= vect);
            ft::vector<int>::reverse_iterator it;
            for (it = vect.rbegin(); it != vect.rend(); it++)
            {
                *it *= 4;
                std::cout << *it << std::endl;
            }

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}

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

int main()
{
    Test *str;
    std::vector<int> vect;

    ft::vector<int> fvect(20, 12);

    
    // vect.push_back(10);
    fvect.resize(24);
    for (ft::vector<int>::iterator it = fvect.begin(); it != fvect.end(); it++)
        std::cout << *it << std::endl;
    return (0);
}

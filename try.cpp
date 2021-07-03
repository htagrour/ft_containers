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
    std::vector<int> vect(5, 10);

    
    // vect.push_back(10);
    try
    {
        ft::vector<int> fvect(vect.begin(), vect.end());
        ft::vector<int> assig(fvect);
        // fvect.resize(fvect.max_size() - 1, 100);
        std::cout << fvect;
        fvect.assign(3, 1);
        std::cout << fvect;
        std::cout << assig;

    }
    catch(const std::exception &e)
    {

        std::cout <<"Execption:" <<e.what() << std::endl;
    }

    return (0);
}

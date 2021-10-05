#include "vector.hpp"
#include <iostream>
#include <vector>
#include <memory>


int main()
{
    ft::vector<int> vet(5,10);

    for (int i = 0; i < 1e8;i++)
        vet.push_back(i* 10);

    // std::cout << vect.capacity() << " "<< vect.size()<< std::endl;
    // // std::vector<int>::const_reverse_iterator it = vect.rbegin();
    // vect.clear();
    for (ft::vector<int>::reverse_iterator it = vet.rbegin();it != vet.rend();it++)
    {
        //  *it = 10;
        std::cout << *it << std::endl;
    }
    //    std::cout << vect.capacity() << " "<< vect.size()<< std::endl;


    return (0);
}
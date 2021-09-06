#include "vector.hpp"
#include <iostream>
#include <vector>
int main()
{
    ft::vector<int> vect;

    for (int i = 0; i < 100;i++)
        vect.push_back(i* 10);

    std::cout << vect.capacity() << " "<< vect.size()<< std::endl;
    // std::vector<int>::const_reverse_iterator it = vect.rbegin();
    vect.clear();
    for (ft::vector<int>::const_iterator it = vect.begin();it != vect.end();it++)
    {
        //  *it = 10;
        std::cout << *it << std::endl;
    }
       std::cout << vect.capacity() << " "<< vect.size()<< std::endl;


    return (0);
}
#include <iostream>
#include <map>
#include "map.hpp"
#include "iterator.hpp"
#include <utility>
#include <fstream>

template<typename T>
void The_test(std::string desc)
{
    int  p[] = {78,49,71 ,-12,60,30,36,72,9,7};
    T map;
    std::ofstream os (desc + ".res");
    
    // std::cout << "------------"<< desc << "------------" << std::endl;
    for (int i = 0; i < 10; i++)
        map.insert(std::pair<int, int>(p[i], p[i]*10));
    // std::cout << "----Citerator-----" << std::endl;
    // for(typename T::const_iterator it = map.begin(); it != map.end(); it++)
    //     std::cout << (*it).first << std::endl;
    os << "----Iterator------" << std::endl;
    for(typename T::iterator it = map.begin(); it != map.end(); it++)
        os << it->first << std::endl;
    os << "----RIterator------" << std::endl;
    for(typename T::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
        os << it->first << std::endl;
    os.close();
}
int main()
{
    The_test<std::map<int,int> >("STD");
    The_test<ft::map<int,int> >("FT");
}
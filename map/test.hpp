#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>
#include <time.h>
#include <chrono>

#define MAX_RAM 4294960000
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))
template<typename T>
void The_test(std::string desc)
{
    // int  p[] = {78,49,71 ,-12,60,30,36,72,9,7};
    T map;
    // std::ofstream os (desc + ".res");
    std::cout << "---------" << desc << "-----------" << std::endl;
    std::cout << map.max_size() << std::endl;
    for (int i = 10; i > 0; i--)
    {
        int r = rand() % 100;
        std::cout << r << std::endl;
        map.insert(ft::pair<int, int>(r, i));
    }
    // std::cout << "----Citerator-----" << std::endl;
    // for(typename T::const_iterator it = map.begin(); it != map.end(); it++)
    //     std::cout << (*it).first << std::endl;

    std::cout << "----Iterator------" << std::endl;
    unsigned int prev = map.begin()->first;
    for(typename T::iterator it = map.begin(); it != map.end(); it++)
    {
        if (prev > it->first)
            {std::cout << "ERROR\n";break;}
        std::cout << it->first << std::endl;
    }
    // std::cout << "----RIterator------" << std::endl;
    // for(typename T::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
    //     std::cout << it->first << std::endl;
    std::cout << "----FIND-----------" << std::endl;
    if (map.find(-12) != map.end())
        std::cout << "-12 is found" << std::endl;
    else
        std::cout << "-12 is not found" << std::endl;
    if (map.find(66) != map.end())
        std::cout << "66 is found" << std::endl;
    else
        std::cout << "66 is not found" << std::endl;
    typename T::iterator it = map.lower_bound(30);
    if (it == map.end())
        std::cout << "out of bound" << std::endl;
    else
        std::cout << it->first << std::endl;
    // os.close();
}

#endif

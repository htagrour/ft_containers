#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>
#include <sys/time.h>
#include <chrono>

#define MAX_RAM 4294960000
#define BUFFER_SIZE 4096
using namespace std::chrono;
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};
time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return(msecs_time);
}
#define COUNT (MAX_RAM / (int)sizeof(Buffer))
template<typename T, typename P>
void The_test(std::string desc)
{
    // int  p[] = {78,49,71 ,-12,60,30,36,72,9,7};
    T map;
    // std::ofstream os (desc + ".res");
    std::cout << "---------" << desc << "-----------" << std::endl;
    // std::cout << COUNT << std::endl;
    for (int i = 0; i < 10000; i++)
    {
        // int r = rand() % COUNT;
        std::cout << map.insert(P(i, i)).second << std::endl;
    }

    std::cout << map.insert(P(0, 0)).second << std::endl;
    // auto start = high_resolution_clock::now();
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // std::cout << duration.count() << std::endl;
        // time_t start = get_time();
        // map.insert(ft::pair<int, int>(1e8 - 1, 30));
        // time_t end = get_time();
        // std::cout << end - start << std::endl;


    // std::cout << "----Citerator-----" << std::endl;
    // for(typename T::const_iterator it = map.begin(); it != map.end(); it++)
    //     std::cout << (*it).first << std::endl;

    // std::cout << "----Iterator------" << std::endl;
    // unsigned int prev = map.begin()->first;
    // for(typename T::iterator it = map.begin(); it != map.end(); it++)
    // {
    //     if (prev > it->first)
    //         {std::cout << "ERROR\n";break;}
    //     std::cout << it->first << std::endl;
    // }
    // std::cout << "----RIterator------" << std::endl;
    // for(typename T::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
    //     std::cout << it->first << std::endl;
    // cout << "-12 is not found" << std::endl;
    // if (map.find(66) != map.end())
    //     std::cout << "66 is found" << std::endl;
    // else
    //     std::cout << "66 is not found" << std::endl;
    
    // for (int i = 0; i <= 10; i++)
    // {
    //     int var = rand() % 100;
    //     typename T::iterator it = map.lower_bound(var);
    //     if (it == map.end())
    //         std::cout << var <<" out of bound" << std::endl;
    //     else
    //         std::cout << var<< " ==>" <<it->first << std::endl;
    // }
    // os.close();
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // std::cout << duration.count() << std::endl;
}

#endif

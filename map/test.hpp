#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>
#include <sys/time.h>
#include <chrono>
#include <stdlib.h> 

#define MAX_RAM 4294960000
#define BUFFER_SIZE 4096
using namespace std::chrono;
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};
#define COUNT 10//(MAX_RAM / (int)sizeof(Buffer))

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return(msecs_time);
}
template <typename T>
void PrintConstIter(T map)
{
    for (typename T::const_iterator it = map.begin(); it != map.end() ; it++)
        std::cout << "F: " << it->first << " S: " << it->second << std::endl;
}

template <typename T, typename P>
void NormalInsert(T& map)
{
    for (int i = 0; i < COUNT; i++)
    {
        if (!map.insert(P(i, i)).second)
        {
            std::cout << "ERROR" << std::endl;
            exit(1);
        }
    }
    if (map.insert(P(rand() % COUNT,0)).second)
    {
        std::cout << "ERROR" << std::endl;
        exit(1); 
    }
}


template <typename T, typename P>
void RangeInsert(T &map, P data)
{
    map.insert(data.begin(), data.end()); 
}

template <typename T>
void printForward(T map)
{
    for (typename T::iterator it = map.begin(); it != map.end();it++)
        std::cout << "F: " << (*it).first << " S: " << (*it).second << std::endl;
}

template <typename T>
void printReverse(T map)
{
    for (typename T::reverse_iterator it = map.rbegin(); it != map.rend();it++)
        std::cout << "F: " << (*it).first << " S: " << (*it).second << std::endl;
}

template <typename T>
void AcessOpInsert(T &map)
{
    for (int i = 0; i < COUNT; i++)
        map[i] = i;
    map[-100] = -101;
    map[COUNT / 2] = 101;
}

template <typename T>
void CapacityTest(T map)
{
    std::cout << "SIZE: " << map.size() << std::endl;
    std::cout << "COUNT: " << map.count() << std::endl;
    std::cout << "MAX_SIZE: " <<  map.max_size() << std::endl;
}

template <typename T>
void OperationsTest(T map)
{
    int element = rand() % COUNT;
    if (map.find(element) == map.end())
        std::cout << element << " NOT EXIST";
    else
        std::cout << element << " IS FOUND";
    std::cout << std::endl;

    std::cout << element<< " COUNT: " <<  map.count(element) << std::endl;
}

template<typename T, typename P>
void The_test(std::string desc)
{
    T map;
    T map2;


    // NormalInsert<T, P>(map);
    AcessOpInsert<T>(map);
    // std::cout << map[9] << std::endl;
    // printForward<T>(map);
    RangeInsert<T, T>(map2, map);
    // printForward<T>(map2);
    // printReverse<T>(map2);
    PrintConstIter<T>(map2);
    OperationsTest<T>(map2);
}

#endif

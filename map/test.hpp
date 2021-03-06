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
#define COUNT 1e8 //(MAX_RAM / (int)sizeof(Buffer))

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return(msecs_time);
}
template <typename T>
void PrintConstIter(const T &map)
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
    if (map.insert(P(COUNT / 2,0)).second)
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
void printForward(const T &map)
{
    for (typename T::const_iterator it = map.begin(); it != map.end();it++)
        std::cout << "F: " << (*it).first << " S: " << (*it).second << std::endl;
}

template <typename T>
void printReverse(const T &map)
{
    for (typename T::const_reverse_iterator it = map.rbegin(); it != map.rend();it++)
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
void CapacityTest(const T &map)
{
    std::cout << "SIZE: " << map.size() << std::endl;
    std::cout << "EMPTY: " << map.empty() << std::endl;
    std::cout << "MAX_SIZE: " <<  map.max_size() << std::endl;
    std::cout << "BEGIN: " << map.begin()->first << std::endl;
}

template <typename T>
void OperationsTest(const T &map)
{
    int element = COUNT / 2;
    if (map.find(element) == map.end())
        std::cout << element << " NOT EXIST";
    else
        std::cout << element << " IS FOUND";
    std::cout << std::endl;


    std::cout << element<< " COUNT: " <<  map.count(element) << std::endl;

    ft::pair<typename T::const_iterator,typename T::const_iterator> p = map.equal_range(element);
    std::cout << element << " LowerBound: ";
    if (p.first == map.end())
        std::cout << " (END)";
    else
        std::cout << p.first->first;
    std::cout << std::endl;


    std::cout << element << " UpperBound: ";
    if (p.second == map.end())
        std::cout << " (END)";
    else
        std::cout << p.second->first;
    std::cout << std::endl;

}
template <typename T>
void erase(T &map)
{
    typename T::iterator it = map.begin();

    for (int i = 0; i < COUNT / 2; i++)
        it++;
    map.erase(map.find(10), map.find(COUNT - 10));
}

template<typename T, typename P>
void The_test(std::string desc)
{
    T map;


    srand(time(NULL));
    NormalInsert<T, P>(map);
    AcessOpInsert<T>(map);
    // map.print();
    erase<T>(map);
    map.print();
    // map.clear();
    printForward<T>(map);
    T map2;
    map.swap(map2);
    // RangeInsert<T, T>(map2, map);
    // printForward<T>(map2);
    // printReverse<T>(map2);
    OperationsTest<T>(map2);
    CapacityTest(map);
}

#endif

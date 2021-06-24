#include <exception>
#include <iostream>
// allocators >>
#include <memory>
#include <list>

int main()
{
    std::allocator<std::string> alloc;
    std::string *array = new std::string[5];
    std::list
    // array = alloc.allocate(sizeof(std::string) * 5);
    // alloc.construct(array, "hello");
    for (int i = -1; i < 15;i++)
        array[i] = "hello";
    for(int i = -1; i < 15; i++)
        std::cout << array[i] << std::endl;
    
    return (0);
}
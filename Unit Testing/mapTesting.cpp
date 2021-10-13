#include "Test.hpp"

template <typename T>
void Test()
{
    T map;
};

int main(int rc, char **args)
{
    if (rc < 2)
        return  0;
    int n = std::atoi(args[1]);

    if (!n)
        Test<std::map>();
    // else
    //     Test();
    return 0;
}
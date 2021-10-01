#include <map>
#include "map.hpp"
#include "test.hpp"

int main()
{
    The_test<ft::map<int,int> , ft::pair<int,int> >("FT");
    // The_test<std::map<int,int> >("STD");
}
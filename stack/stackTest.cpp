#include <stack>
#include <iostream>
#include "stack.hpp"
int main()
{
    ft::stack<int> st;

    for (int i = 0; i < 15; i++)
        st.push(i);
    while (!st.empty())
    {
        std::cout << st.top() << std::endl;
        st.pop();
    }
    
    return (0);
}
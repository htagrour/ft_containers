#include <iostream>
#include <list>
#include <memory>
#include<iterator>
#include <cstddef>

// class Iterator
// {

// }

class Integers
{
    public:
        struct Iterator 
        {
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = int;
            using pointer           = int*;
            using reference         = int&;

            Iterator(pointer ptr) : m_ptr(ptr) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() { return m_ptr; }
            Iterator& operator++() { m_ptr++; return *this; }  
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };  

        private:
            pointer m_ptr;
        };

        Iterator begin() { return Iterator(&m_data[0]); }
        Iterator end()   { return Iterator(&m_data[200]); }

    private:
        int m_data[200];
};

int main(void)
{
    Integers cont;
    // std::list
    for (Integers::Iterator it = cont.begin(); it != cont.end();it++)
    {
        *it = 10;
    }
    for (Integers::Iterator it = cont.begin(); it != cont.end();it++)
    {
        std::cout << *it << std::endl;
    }
    return (0);
}
// https://www.youtube.com/watch?v=F9eDv-YIOQ0
// https://internalpointers.com/post/writing-custom-iterators-modern-cpp
// http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html
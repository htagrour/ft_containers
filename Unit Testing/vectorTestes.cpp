#include "Test.hpp"
#define COUNT 1e1
template <typename T>
void printfForward(const T &container)
{
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << std::endl;
}

template<typename T>
void printContent(const T &vect)
{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Size:" << vect.size() << std::endl;
    std::cout << "Capacity:" << vect.capacity() << std::endl;
    std::cout << "Empty:" << vect.empty() << std::endl;
    std::cout << "Max_size:" << vect.max_size() << std::endl; 
    std::cout << "Front:" << vect.front() << std::endl;
    std::cout << "Back:" << vect.back() << std::endl;
    std::cout << "Access At [size / 2]: " << vect[vect.size() / 2] << std::endl;
    std::cout << "Content:" << std::endl;
    printfForward<T>(vect);
}
template <typename T>
void Contructor_Destructor()
{
    T vect(COUNT , 100);
    T copyConst(vect);
    T rangConst(copyConst.begin(), copyConst.end());
    printContent<T>(rangConst); 
}

template <typename T>

void AssignOpeartor()
{
    T vect(COUNT, -12);
    T vect2 ;

    vect = vect2;
    printContent<T>(vect);
}

template <typename T>
void Iterators()
{
    T vect;

    for (int i = 0; i < COUNT ; i++)
        vect.push_back(i);
    typename T::iterator it = vect.begin();
    std::cout << "At index 0 :" << it[0] << std::endl;
    std::cout << "At index COUNT/2: " << it[COUNT / 2] << std::endl;

    it = it + COUNT / 2;
    std::cout << "Reference: " << *it << std::endl;

    std::cout << "REVERSE ITERAROR" << std::endl;

    for (typename T::reverse_iterator rIt = vect.rbegin(); rIt != vect.rend(); rIt++)
        std::cout << *rIt << std::endl;
    
    std::cout << "CONST ITEARATOR" << std::endl;

    for (typename T::const_iterator cIt = vect.begin(); cIt != vect.end(); cIt++)
        std::cout << *cIt << std::endl;
}

template <typename T>
void Capacity()
{
    T vect(COUNT, -12);
    printContent<T>(vect);
    vect.resize(COUNT / 2, 20);
    printContent<T>(vect);
    vect.resize(COUNT * 2, 20);
    printContent<T>(vect);
    vect.reserve(COUNT * 3);
    printContent<T>(vect);

    try
    {
        std::cout << vect.at(COUNT * 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

}

int main()
{
    // Contructor_Destructor<ft::vector<int> >();
    // AssignOpeartor<ft::vector<int> >();
    // Iterators<ft::vector<int> >();
    Capacity<ft::vector<int> >();
}
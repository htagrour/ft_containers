#include "Test.hpp"
#define COUNT 1e5
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
    if (vect.size())
    {
        std::cout << "Front:" << vect.front() << std::endl;
        std::cout << "Back:" << vect.back() << std::endl;
        std::cout << "Access At [size / 2]: " << vect[vect.size() / 2] << std::endl;
    }
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

    for (int i = 0; i < COUNT; i++)
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
        std::cout << vect.at(COUNT) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

}

template<typename T>
void Modifiers()
{
    T vect;
    T vect2;

    vect.assign(COUNT , -12);

    vect2.assign(vect.begin(), vect.end());
    vect2.assign(vect.begin(), vect.begin() + COUNT / 2);
    for (int i = COUNT; i < COUNT * 2; i++)
        vect2.push_back(i);
    int size = vect2.size();
    for (int i = 0; i < size / 2 ; i++)
        vect2.pop_back();
    vect2.insert(vect2.begin() + 4, 4,0);
    vect.insert(vect.begin(), vect2.end() - 3, vect2.end());
    vect.erase(vect.end() - 3, vect.end());
    printContent<T>(vect);
    vect.clear();
    printContent<T>(vect);
    vect.swap(vect2);
    printContent<T>(vect);
}

template <typename T>
void RelationalOperators()
{
    T vect1(COUNT, 20);
    T vect2(COUNT, 20);
    T vect3(COUNT, 0);

    std::cout << (vect1 == vect2) << std::endl;
    std::cout << (vect1 == vect3) << std::endl;
    std::cout << (vect1 < vect3) << std::endl;
    std::cout << (vect1 > vect3) << std::endl;
}

#define TYPE std
int main()
{
    Contructor_Destructor<TYPE::vector<int> >();
    AssignOpeartor<TYPE::vector<int> >();
    Capacity<TYPE::vector<int> >();
    Iterators<TYPE::vector<int> >();
    Modifiers<TYPE::vector<int> >();
    RelationalOperators<TYPE::vector<int> >();
}
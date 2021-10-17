#include "Test.hpp"
#define TYPE std
#define COUNT 1e6

template<typename T>
class MutantStack : public T
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename T::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

template <typename T>
void printContent(T& stack)
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << "EMPTY:" << stack.empty() << std::endl;
    std::cout << "Size:" << stack.size() << std::endl;
    if (!stack.empty())
        std::cout << "Top:" << stack.top() << std::endl;
}

template <typename T>
void Constructor()
{
    std::cout << "---CONSTRUCTOR-----" << std::endl;
    T stack1;
    TYPE::vector<int> vect(COUNT, -12);
    TYPE::vector<int> vect2;
    T stack2(vect);
    T stack3(vect2);

    for (int i = 0; i < COUNT; i++)
        stack1.push(i);
    printContent(stack1);
    printContent(stack2);
    printContent(stack3);
}
template <typename T>
void printForward(T& Mstack)
{
    for(typename T::iterator it = Mstack.begin(); it!= Mstack.end(); it++)
        std::cout << *it << std::endl;
}
template <typename T>
void pushAndPop()
{
    std::cout << "---pushAndPop-----" << std::endl;

    MutantStack<T> Mstack;

    for (int i = 0; i < COUNT; i++)
        Mstack.push(i);
    printForward(Mstack);
    std::cout << "~~~~~~~" << std::endl;
    for (int i = 0; i < COUNT / 2; i++)
        Mstack.pop();
    printForward(Mstack);
}

template <typename T>
void RelationalOperators()
{
    TYPE::vector<int> vect1(COUNT, -12);
    TYPE::vector<int> vect2(COUNT, 12);
    T stack1(vect1);
    T stack2(vect2);

    std::cout << (stack1 == stack2) << std::endl;
    std::cout << (stack1 == stack1) << std::endl;
    std::cout << (stack1 > stack2) << std::endl;
    std::cout << (stack1 < stack2) << std::endl;
}

int main()
{
    std::cout << "STACK TESTS" << std::endl;
    Constructor<TYPE::stack<int , TYPE::vector<int> > >();
    pushAndPop<TYPE::stack<int , TYPE::vector<int> > >();
    RelationalOperators<TYPE::stack<int , TYPE::vector<int> > >();
}
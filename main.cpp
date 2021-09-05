#include <iostream>
#include <list>
namespace ft
{
    
    class test
    {
        private:
            std::string name;
            int number;
        public:
            test(std::string name)
            {
                this->name = name;
                this->number = 12;
            }
            std::string getName() const { return name;}
            int getNum() const { return number;}
            operator int() { return 1000;}

    };

    int operator+(int i, const test&t)
    {
        return (100);
    }

    std::ostream &operator <<(std::ostream &os, const test &T)
    {
        os << T.getName() << " heloo wlr" << std::endl;
        return os;
    }
}

int main()
{
    ft::test t("hamza");
    int res = 1 + t;

    int cast = t;
    std::cout << res << std::endl;
    return (0);
}
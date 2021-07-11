#include <iostream>
#include <map>
#include "mapUtils.hpp"
#include "map.hpp"
template <typename T>
class Node
{
    public:
        T _data;
        Node *_left;
        Node *_right;
        Node(T data):_data(data), _left(NULL), _right(NULL){}
        Node(T data, Node* left, Node* right): _data(data), _left(left),_right(right){};
};
template <typename T>
class Tree
{
    private:
        Node<T>* _root;
    public:
        Tree():_root(NULL){};
        void insert(T data)
        {
            Node<T> *new_node = new Node<T>(data);
            if (!_root)
                _root = new_node;
            else
            {
                Node<T> *p = _root;

                while(p)
                {
                    if (data > p->_data)
                    {
                        if (!p->_right)
                            break;
                        else
                            p = p->_right;
                    }
                    else
                    {
                        if (!p->_left)
                            break;
                        else
                            p = p->_left;   
                    }
                }
                if (data > p->_data)
                    p->_right = new_node;
                else
                    p->_left = new_node;
            }
        }
        void printTree()
        {
            printBT("", _root, false);            
        }

        void printBT(const std::string& prefix, const Node<T>* node, bool isLeft)
        {
            if( node != nullptr )
            {
                std::cout << prefix;

                std::cout << (isLeft ? "|──" : "└──" );

                // print the value of the node
                std::cout << node->_data << std::endl;

                // enter the next tree level - left and right branch
                printBT( prefix + (isLeft ? "│   " : "    "), node->_left, true);
                printBT( prefix + (isLeft ? "│   " : "    "), node->_right, false);
            }
        }
        int find(T to_find)
        {
            Node<T> *tmp;

            tmp = _root;
            while(tmp)
            {
                if (tmp->_data == to_find)
                    return (1);
                tmp = (to_find > tmp->_data) ? tmp->_right : tmp->_left;
            }
            return (0);
        }
};

int main()
{
    ft::map<int, int> mp;

    srand(time(NULL));
    for (int i = 1; i< 10; i++)
        mp.insert(std::make_pair<int, int>(i, 0));
    // std::cout << (++mp.begin())->_data.first << std::endl;
    ft::map<int, int>::iterator it = mp.begin();
    for (int i = 1;i < mp.size();i++ )
    {
        std::cout << it->_data.first << std::endl;
        it++;
    }
    return (0);
}
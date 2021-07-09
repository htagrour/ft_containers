#include <iostream>
#include <map>
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
    // Tree<int> t;
    int i;
    // // for (int i = 0;i < 10; i++)
    // //     t.insert(i);
    srand(time(NULL));
    // std::cout << std::endl << std::endl;
    // t.printTree();
    // std::cout << t.find(-12);
    std::map<int, int> mapi;

    for (int j = 20;j > 9; j--)
    {
        i = rand() % 20;
        // std::cout << i  << " ";
        mapi.insert(std::pair<int, int>(i, i * 10));
    }
    // mapi.insert(std::pair<int, int>(150,12));
    mapi.insert(mapi.begin(), std::pair<int, int>(130,12));
    for (std::map<int, int>::iterator it = mapi.begin(); it != mapi.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    return (0);
}
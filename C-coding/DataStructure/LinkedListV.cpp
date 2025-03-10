#include <iostream>

using namespace std;

template<typename HeadType>
class HeadNode
{
public:
    HeadType Hdata;
    HeadNode<typename> *first;
}

HeadNode<int>* Headptr; // 初始化头节点

template<typename type>
class Node
{
public:
    type data;
    Node<type> *link;
}



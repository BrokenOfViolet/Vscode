#include <iostream>

using namespace std;

template<class HeadType, class ElementType>
class SimpleChainList
{
public:
    SimpleChainList() // 构造一个带表头节点的链表 {
        HeadPtr = new SimpleHeadNode<HeadType>;
        HeadPtr->first = NULL;
    }
    ~SimpleChainList() {
        delete HeadPtr;
    }
    
private:
    SimpleHeadNode<HeadType> *HeadPtr;
}

int main()
{
    SimpleChainList<int,int> *head;
    
}
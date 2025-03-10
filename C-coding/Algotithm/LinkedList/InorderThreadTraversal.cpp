#include <iostream>

using namespace std;


template<class ElementType>
class BinaryTreeNode
{
public:
    ElementType data;
    BinaryTreeNode *Lchild;
    bool Lflag;
    BinaryTreeNode *Rchild;
    bool Rflag;
};

template<ElementType>
void BinaryTreeNode<ElementType>::
InorderThreadTraversal(BinaryTreeNode *root) {
    BinaryTreeNode *p = root;
    bool flag;
    while (p) {
        while (!p->Lflag)
            p = p->Lchild;
        flag = true;
        while (flag && p) {
            cout << p->data << " ";
            if (!p->Rflag) {
                flag = p->Rflag;
            }
            p = p->Rchild;
        }
    }
}
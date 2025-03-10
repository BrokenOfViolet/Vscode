#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct ListNode
{
    T exp;      // 指数
    T coef;     // 系数
    ListNode *next;

    ListNode(T x, T y) : exp(x), coef(y), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        while (head != nullptr) {
            ListNode<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void append(T exp, T coef) {
        ListNode<T> *newNode = new ListNode<T>(exp, coef);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode<T> *current = head;
            while (current->next != nullptr) {
                current = current->next;
            } current->next = newNode;
        }
    }
    void printList() {
        ListNode<T> *temp = head;
        while (temp != nullptr) {
            cout << temp->coef << "*" << "x^" << temp->exp << "+";
            temp = temp->next;
        } cout << endl;
    }
    void AddPolyL(ListNode<T>* L1, ListNode<T>* L2) {
        ListNode<T> *p = L1, *q = L2;
        int choice;
        while (p && q) {
            if (p->exp < q->exp)
                choice = 1;
            if (p->exp == q->exp)
                choice = 2;
            if (p->exp > q->exp)
                choice = 3;
            switch(choice) {
                case 1: 
                {
                    this->append(q->exp,q->coef);
                    q = q->next;
                    break;
                }
                case 2:
                {
                    int coef = p->coef+q->coef;
                    this->append(p->exp, coef);
                    p = p->next;
                    q = q->next;
                    break;
                }
                case 3:
                {
                    this->append(p->exp,p->coef);
                    p = p->next;
                    break;
                }
            }
        }
        while (p) {
            this->append(p->exp, p->coef);
            p = p->next;
        }
        while (q) {
            this->append(q->exp, q->coef);
            q = q->next;
        }
    }
private:
    ListNode<T> *head;
};

template<typename T>
ListNode<T>* append(T exp, T coef, ListNode<T>* L) {
    ListNode<T> *newNode = new ListNode<T>(exp,coef);
    if (L == nullptr) {
        L = newNode;
        return L;
    } else {
        ListNode<T>* curr = L;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        return L;
    }
}

int main()
{
    ListNode<int> *L1=nullptr;
    ListNode<int> *L2=nullptr;
    L1 = append(200,5,L1);
    L1 = append(100,3,L1);
    L1 = append(5,2,L1);
    L2 = append(150,4,L2);
    L2 = append(100,-3,L2);
    L2 = append(5,1,L2);
    L2 = append(3,7,L2);
    L2 = append(0,2,L2);

    LinkedList<int> L3;
    L3.AddPolyL(L1,L2);
    L3.printList();

    return 0;
}

    // LinkedList<int> L1;
    // L1.append(200,5);
    // L1.append(100,3);
    // L1.append(5,2);
    // L1.printList();

    // LinkedList<int> L2;
    // L2.append(150,4);
    // L2.append(100,-3);
    // L2.append(5,1);
    // L2.append(3,7);
    // L2.append(0,2);
    // L2.printList();

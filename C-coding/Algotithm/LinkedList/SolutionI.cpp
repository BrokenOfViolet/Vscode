#include <iostream>

using namespace std;

template<typename T>
struct ListNode
{
    T val;
    ListNode *next;

    ListNode(T x) : val(x), next(nullptr) {}
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
    void append(T val) {
        ListNode<T> *newNode = new ListNode<T>(val);
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
            cout << temp->val << " ";
            temp = temp->next;
        } cout << endl;
    }

private:
    ListNode<T> *head;
};

int main()
{
    LinkedList<int> myList;
    myList.append(5);
    myList.append(2);
    myList.append(0);
    myList.printList();
    return 0;
}

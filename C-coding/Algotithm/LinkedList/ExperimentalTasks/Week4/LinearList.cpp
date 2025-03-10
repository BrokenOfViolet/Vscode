#include <iostream>
#include <string>
#include <cstring>
// 实现链表的增删查改
// 这个程序可能不太具有泛用性
using namespace std;

template<class T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T x) : data(x), next(NULL) {}
};

template<class T>
class LinkedList
{
public:
    LinkedList() : head(NULL) {}
    ~LinkedList() {
        Node<T> *current = head;
        Node<T> *next;
        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    void display() {
        Node<T> *temp = head;
        while (temp != NULL) {
            cout << "name:" << (temp->data).name<<"\tage:" << (temp->data).age << endl; // 这里是输出person结构体的内容
            temp = temp->next;
        }
    }
    void Append(T x) {
        Node<T> *newNode = new Node<T>(x);
        Node<T> *current = head;
        if (current == NULL) {
            head = newNode;
            return;
        }
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    void Delete(int index) { // 这是按索引删除节点，不同于C中用内容删除节点
        if (head == NULL || index < 0) {
            cout << "Linked List is a empty list Or Index out of range" << endl;
            return;
        }
        Node<T> *current = head;
        if (index == 0) {
            head = current->next;
        } else {
            for (int i=0; i<index-1; i++) {
            current = current->next;
            }
            Node<T> *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
    void search(const char searchkey[]) {
        Node<T> *current = head;
        while (current != NULL) {
            if (!strcmp(current->data.name.c_str(), searchkey)) {
                cout << "Find the searchkey and input below:" << endl;
                cout << "name:" << current->data.name << "\tage:" << current->data.age << endl;
                return;
            }
            current = current->next;
        }
        cout << "Can not find the searchkey!" << endl;
    }
private:
    Node<T> *head;
};

struct person
{
    string name;
    int age;
};

int main()
{
    LinkedList<person> personList;
    person pers1 = {"仆人",19};
    person pers2 = {"公子",20};
    person pers3 = {"散兵",18};
    personList.Append(pers1);
    personList.Append(pers2);
    personList.Append(pers3);

    cout << "Display:" << endl;
    personList.display();
    cout << endl << endl;

    personList.search("公子");
    cout << endl << endl;

    personList.Delete(2);
    personList.display();

    return 0;
}
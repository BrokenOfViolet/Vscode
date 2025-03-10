#include <iostream>
using namespace std;

template<class QueueType>
class Queue {
public:
    Queue(int MaxQueueSize = 20) : front(-1), rear(-1), MaxSpaceSize(MaxQueueSize) {
        element = new QueueType[MaxSpaceSize];
    }
    ~Queue() { delete [] element; }
    bool IsEmpty() { return (front==-1 && rear==-1); }
    bool IsFull() { return front == (rear+1)%MaxSpaceSize; }
    bool GetFront(QueueType& result) {
        if (IsEmpty())
            return false;
        result = element[front];
        return true;
    }
    bool GetRear(QueueType& result) {
        if (IsEmpty())
            return false;
        result = element[rear];
        return true;
    }
    bool EnQueue(const QueueType& newValue) { // Changed to const reference
        if (IsFull()) {
            cerr << "The Queue is full"<<endl;
            return false;
        }
        rear = (rear+1)%MaxSpaceSize;
        element[rear] = newValue;
        return true;
    }
    bool DeQueue(QueueType& result) {
        if (IsEmpty()) {
            cerr << "The Queue is empty"<<endl;
            return false;
        }
        result = element[front];
        front = (front+1)%MaxSpaceSize;
        if (rear == front) {
            rear = front = -1;
        }
        return true;
    }

private:
    QueueType *element;
    int front;
    int rear;
    int MaxSpaceSize;
};

class ElementItem {
public:
    int CarriageNumber;
};

bool RearrangementTrack(int CarriageNumber[], const int CarriageQuantity, const int HoldQueueQuantity)
{
    int MaxQueueSize = 20;
    ElementItem result;
    Queue<ElementItem> *QueueHold = new Queue<ElementItem>[HoldQueueQuantity];
    for (int i = 0; i < HoldQueueQuantity; i++) { // Initialize QueueHold array
        QueueHold[i] = Queue<ElementItem>(MaxQueueSize);
    }
    for (int i = 0; i < CarriageQuantity; i++) {
        result.CarriageNumber = CarriageNumber[i];
        ElementItem rear_number;
        int k = 0;
        for (k = 0; k < HoldQueueQuantity; k++) {
            QueueHold[k].GetRear(rear_number);
            if (result.CarriageNumber > rear_number.CarriageNumber || QueueHold[k].IsEmpty()) {
                QueueHold[k].EnQueue(result);
                break;
            }
        }
        if (k == HoldQueueQuantity) // All queues are full
            return false;
    }
    for (int i = 0; i < CarriageQuantity; i++) {
        ElementItem min_carr;
        int index = 0; // Index of the queue with minimum carriage number
        min_carr.CarriageNumber = INT_MAX; // Initialize min_carr with maximum value
        for (int j = 0; j < HoldQueueQuantity; j++) {
            QueueHold[j].GetFront(result);
            if (!QueueHold[j].IsEmpty() && result.CarriageNumber < min_carr.CarriageNumber) {
                min_carr = result;
                index = j;
            }
        }
        QueueHold[index].DeQueue(min_carr);
        cout << min_carr.CarriageNumber << " ";
    }
    delete[] QueueHold; // Deallocate memory
    return true;
}


int main() 
{
    const int CarriageQuantity = 9;
    const int HoldQueueQuantity = 4;
    int CarriageNumber[CarriageQuantity] = {4,7,1,5,8,6,9,2,3};
    RearrangementTrack(CarriageNumber,CarriageQuantity,HoldQueueQuantity);
    return 0;
}

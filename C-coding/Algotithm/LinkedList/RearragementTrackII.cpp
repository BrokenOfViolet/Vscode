#include <iostream>

using namespace std;

template<class QueueType>
class Queue
{
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
    bool EnQueue(QueueType& newValue) {
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

class ElementItem
{
public:
    int CarriageNumber;
};

bool RearrangementTrack(int CarriageNumber[],const int CarriageQuantity,const int HoldQueueQuantity)
// CarriageNumber[] : 车厢的初始排列  CarriageQuantity : 车厢的数量  HoldQueueQuantity : 缓冲轨的数量
{
    int MaxQueueSize = 20;
    int k=0;
    ElementItem result;
    Queue<ElementItem> *QueueHold = new Queue<ElementItem>[HoldQueueQuantity];
    Queue<ElementItem> QueueOut;
    for (int i=0; i<CarriageQuantity; i++) {
        result.CarriageNumber = CarriageNumber[i];
        ElementItem rear_number;
        if (QueueHold[0].IsEmpty()) {
            QueueHold[0].EnQueue(result);
        }
        for (k=0; k<HoldQueueQuantity; k++) {
            QueueHold[k].GetRear(rear_number);
            if (result.CarriageNumber > rear_number.CarriageNumber) {
                QueueHold[k].EnQueue(result);
            }
            if (QueueHold[k].IsEmpty()) {
                QueueHold[k].EnQueue(result);
            }
        }
        if (k==HoldQueueQuantity)
            return false;
    }
    for (int i=0; i<CarriageQuantity; i++) {
        ElementItem min_carr;
        int index;
        min_carr.CarriageNumber = CarriageQuantity;
        for (int i=0; i<HoldQueueQuantity; i++) {
            QueueHold[i].GetFront(result);
            if (result.CarriageNumber < min_carr.CarriageNumber) {
                min_carr = result;
                index = i;
            }
            if (QueueHold[i].IsEmpty())
                break;
        }
        QueueHold[index].DeQueue(min_carr);
        QueueOut.EnQueue(min_carr);
        cout << min_carr.CarriageNumber << " ";
    }
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
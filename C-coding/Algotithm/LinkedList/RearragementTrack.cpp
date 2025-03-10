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


bool Hold(Queue<ElementItem> QueueHold[],int CarriageQuantity, int HoldQueueQuantity,int &MinHold,
        int &MinQueue, int &NowOut, int &current) // 为车厢current寻找最优缓冲铁轨，如果没有，return false
// MinHold是已进入各缓冲轨道中编号最小的车厢，MinQueue是MinHold编号车厢所在的缓冲队列编号
{
    int BestCushion = -1;   // 最优缓冲队列编号，为-1表示还未找到最优缓冲铁轨
    int BestLast = -1;      // BestLast保存BestCushion中最后一节车厢的编号
    ElementItem temp;
    for (int i=0; i<HoldQueueQuantity; i++) {
        if (!QueueHold[i].IsEmpty()) {
            QueueHold[i].GetRear(temp);
            if (current>temp.CarriageNumber && temp.CarriageNumber>BestLast) {
                BestLast = temp.CarriageNumber;
                BestCushion = i;
            }
        } else 
            if (BestCushion == -1) BestCushion = i;
    }
    if (BestCushion == -1) {
    cout << "Wrong!!!Can not Hold" << endl;
    return false;
    }
    temp.CarriageNumber = current;
    QueueHold[BestCushion].EnQueue(temp);
    cout <<"【入轨到缓冲】从入轨将" << current << "号车厢移到最优缓冲铁轨"<<BestCushion<<endl;
    if (current < MinHold) {
        MinHold = current;
        MinQueue = BestCushion;
    }
    return true;
}

void Output(Queue<ElementItem> *QueueHold, Queue<ElementItem> &QueueIn, Queue<ElementItem> &QueueOut,
            int CarriageQuantity, int HoldQueueQuantity, int &MinHold, int &MinQueue, int &NowOut)
// 从MinQueue中输出最小车厢MinHold,并寻找最小的MinHold和MinQueue
{
    int current;
    ElementItem temp;
    QueueHold[MinQueue].DeQueue(temp);
    cout << "【缓冲到出轨】从" << MinQueue << "号缓冲铁轨输出,"<<MinHold<<"号车厢到出轨" <<endl;
    MinHold = CarriageQuantity + 1;
    for (int i=0; i<HoldQueueQuantity; i++) {
        QueueHold[i].GetFront(temp);
        current = temp.CarriageNumber;
        if (!QueueHold[i].IsEmpty() && current < MinHold) {
            MinHold = current;
            MinQueue = i;
        }
    }
}

bool RearrangementTrack(int CarriageNumber[], int CarriageQuantity, int HoldQueueQuantity)
// CarriageNumber[] : 车厢的初始排列  CarriageQuantity : 车厢的数量  HoldQueueQuantity : 缓冲轨的数量
{
    int MaxQueueSize = 20;
    ElementItem result;
    Queue<ElementItem> QueueIn(MaxQueueSize);
    for (int i=0; i<CarriageQuantity; i++) {
        result.CarriageNumber = CarriageNumber[i];
        QueueIn.EnQueue(result);
    }
    Queue<ElementItem> QueueOut(MaxQueueSize);
    Queue<ElementItem> *QueueHold = new Queue<ElementItem>[HoldQueueQuantity];
    int NowOut = 1; // 当前应该输出的车厢号
    int MinHold = CarriageQuantity+1;   // MinHold是已进入各缓冲铁轨中编号最小的车厢,初值为最大值
    int MinQueue = 0;
    for (int i=0; i<CarriageQuantity; i++) {
        QueueIn.DeQueue(result);
        if (result.CarriageNumber == NowOut) {
            cout << "【入轨到出轨】从入轨输出" << result.CarriageNumber << "号车厢到出轨" <<endl;
            QueueOut.EnQueue(result);
            if (NowOut != CarriageQuantity)
                NowOut++;
            while(MinHold == NowOut) { // 这个while循环主体和上面差不多，但是多了一个修改MinHold的操作，因为MinHild进队列
                result.CarriageNumber = MinHold;
                QueueOut.EnQueue(result);
                Output(QueueHold,QueueIn,QueueOut,CarriageQuantity,HoldQueueQuantity,MinHold,MinQueue,NowOut);
                // 修改MinHold的值
                if (NowOut != CarriageQuantity) // 这个和上面的一样
                    NowOut++;
            }
        } else { // 将result.CarriageNumber送入某个轨道
            if(!Hold(QueueHold,CarriageQuantity,HoldQueueQuantity,MinHold,MinQueue,NowOut,result.CarriageNumber))
                return false;
        }
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
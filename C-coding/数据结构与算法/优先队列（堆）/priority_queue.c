#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义节点结构体
typedef struct {
    int data;
    int priority;
} Node;

// 定义优先队列结构体
typedef struct {
    Node heap[MAX_SIZE];
    int size;
} PriorityQueue;

// 初始化优先队列
PriorityQueue* initPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

// 插入元素到优先队列
void enqueue(PriorityQueue* pq, int data, int priority) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority queue is full.\n");
        return;
    }
    
    // 插入新节点到队尾
    pq->heap[pq->size].data = data;
    pq->heap[pq->size].priority = priority;
    pq->size++;
    
    // 重新调整堆使其满足最小堆性质
    int idx = pq->size - 1;
    while (idx > 0 && pq->heap[(idx - 1) / 2].priority > pq->heap[idx].priority) {
        // 交换节点
        Node temp = pq->heap[(idx - 1) / 2];
        pq->heap[(idx - 1) / 2] = pq->heap[idx];
        pq->heap[idx] = temp;
        // 移动到父节点
        idx = (idx - 1) / 2;
    }
}

// 从优先队列中删除并返回具有最小优先级的元素
Node dequeue(PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority queue is empty.\n");
        return (Node){-1, -1};
    }
    
    // 保存队首节点
    Node minNode = pq->heap[0];
    // 将最后一个节点移动到队首
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    
    // 重新调整堆使其满足最小堆性质
    int idx = 0;
    while (1) {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        int smallest = idx;
        
        // 找到左右子节点中优先级最小的节点
        if (leftChild < pq->size && pq->heap[leftChild].priority < pq->heap[smallest].priority)
            smallest = leftChild;
        if (rightChild < pq->size && pq->heap[rightChild].priority < pq->heap[smallest].priority)
            smallest = rightChild;
        
        // 如果最小的子节点的优先级比当前节点小，则交换节点并继续向下调整
        if (smallest != idx) {
            Node temp = pq->heap[smallest];
            pq->heap[smallest] = pq->heap[idx];
            pq->heap[idx] = temp;
            idx = smallest;
        } else {
            break;
        }
    }
    
    return minNode;
}

int main() {
    // 初始化优先队列
    PriorityQueue* pq = initPriorityQueue();
    
    // 插入一些元素
    enqueue(pq, 10, 3);
    enqueue(pq, 20, 2);
    enqueue(pq, 30, 4);
    enqueue(pq, 40, 1);
    
    // 依次删除并打印元素
    while (pq->size > 0) {
        Node minNode = dequeue(pq);
        printf("Data: %d, Priority: %d\n", minNode.data, minNode.priority);
    }
    
    // 释放内存
    free(pq);
    
    return 0;
}

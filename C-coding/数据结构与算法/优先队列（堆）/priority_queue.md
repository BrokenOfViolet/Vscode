优先队列（Priority Queue）是一种数据结构，其每个元素都具有优先级。在访问元素时，总是优先级最高的元素最先被访问。优先队列可以用多种方式实现，最常见的是使用堆（Heap）。

### 优先队列的基本操作

1. **插入（Insert）**：将一个元素添加到优先队列中，并根据其优先级将其放置在正确的位置。
2. **查找最小（最大）元素（Find-Min/Find-Max）**：获取优先级最高的元素（通常是最小或最大），但不删除它。
3. **删除最小（最大）元素（Delete-Min/Delete-Max）**：移除并返回优先级最高的元素。
4. **改变优先级（Change Priority）**：改变某个元素的优先级，并重新调整优先队列。

### 实现方式

1. **二叉堆（Binary Heap）**：
   - **最小堆（Min-Heap）**：父节点的优先级总是小于或等于其子节点。
   - **最大堆（Max-Heap）**：父节点的优先级总是大于或等于其子节点。

2. **斐波那契堆（Fibonacci Heap）**：
   - 更加复杂，但在某些操作（如合并队列）上具有更好的时间复杂度。

3. **二项队列（Binomial Queue）**：
   - 使用一系列二项树来组织元素。

4. **配对堆（Pairing Heap）**：
   - 通过一系列配对操作来维持堆结构。

### 应用

优先队列在许多算法和系统中有广泛的应用，包括但不限于：

1. **Dijkstra算法**：用于找到图中的最短路径。
2. **A*算法**：用于路径规划。
3. **任务调度**：操作系统中用于管理任务的执行顺序。
4. **数据流处理**：处理连续输入的数据流。

优先队列是一种数据结构，支持快速插入和删除具有最高（或最低）优先级的元素。优先队列可以通过堆（Heap）来实现，最常见的是二叉堆。

下面是一个用C语言实现优先队列的示例，包括其基本操作：

### 二叉堆实现优先队列

#### 1. 二叉堆的基本结构

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

typedef struct {
    int data[MAX_HEAP_SIZE];
    int size;
} PriorityQueue;

// 初始化优先队列
PriorityQueue* createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

// 交换两个整数的值
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 插入元素
void insert(PriorityQueue *pq, int value) {
    if (pq->size >= MAX_HEAP_SIZE) {
        printf("Heap is full\n");
        return;
    }

    pq->size++;
    int i = pq->size - 1;
    pq->data[i] = value;

    // 上浮操作
    while (i != 0 && pq->data[(i - 1) / 2] > pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 获取并删除最小元素
int extractMin(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->data[0];
    }

    int root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapify(pq, 0);

    return root;
}

// 下沉操作
void heapify(PriorityQueue *pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->data[left] < pq->data[smallest])
        smallest = left;

    if (right < pq->size && pq->data[right] < pq->data[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&pq->data[i], &pq->data[smallest]);
        heapify(pq, smallest);
    }
}

// 打印优先队列
void printPriorityQueue(PriorityQueue *pq) {
    for (int i = 0; i < pq->size; i++)
        printf("%d ", pq->data[i]);
    printf("\n");
}

// 主函数
int main() {
    PriorityQueue *pq = createPriorityQueue();
    
    insert(pq, 3);
    insert(pq, 2);
    insert(pq, 1);
    insert(pq, 7);
    insert(pq, 5);

    printf("Priority Queue: ");
    printPriorityQueue(pq);

    printf("Extracted Min: %d\n", extractMin(pq));
    printf("Priority Queue after extraction: ");
    printPriorityQueue(pq);

    free(pq);
    return 0;
}
```

### 代码解释

1. **PriorityQueue 结构**：
   - `data`：存储堆元素的数组。
   - `size`：当前堆中元素的数量。

2. **createPriorityQueue 函数**：
   - 创建并初始化一个新的优先队列。

3. **swap 函数**：
   - 交换两个整数的值。

4. **insert 函数**：
   - 将新元素插入到堆中。
   - 新元素首先被放置在数组的末尾，然后通过上浮操作确保堆的性质（最小堆）得以维持。

5. **extractMin 函数**：
   - 获取并删除堆中的最小元素（堆顶元素）。
   - 用数组的最后一个元素替换堆顶元素，然后通过下沉操作恢复堆的性质。

6. **heapify 函数**：
   - 下沉操作，确保子树满足堆的性质。
   - 递归地将较大的元素下沉，直到子树成为最小堆。

7. **printPriorityQueue 函数**：
   - 打印优先队列中的元素。

8. **main 函数**：
   - 创建优先队列，插入几个元素，打印优先队列，提取最小元素并再次打印优先队列。

### 二叉堆的操作原理

- **插入操作**：
  - 插入元素后，上浮操作确保新元素逐层与父节点比较并交换位置，直到堆的性质恢复。

- **删除最小元素操作**：
  - 提取堆顶元素后，用最后一个元素替换堆顶，并进行下沉操作，将新堆顶元素逐层与子节点比较并交换位置，直到堆的性质恢复。

这些操作确保了优先队列在插入和删除元素时的时间复杂度为 \(O(\log n)\)，其中 \(n\) 是堆中元素的数量。这使得二叉堆成为实现优先队列的高效数据结构。
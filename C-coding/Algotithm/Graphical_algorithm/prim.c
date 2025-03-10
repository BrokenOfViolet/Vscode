#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NumVertex 7

typedef int Vertex;

typedef struct {
    bool Known;
    int Dist;
    Vertex Path;
} TableEntry;

typedef TableEntry Table[NumVertex];

// 优先队列的节点结构
typedef struct {
    Vertex v;
    int dist;
} PQNode;

// 优先队列结构
typedef struct {
    PQNode elements[NumVertex];
    int size;
} PriorityQueue;

// 初始化优先队列
void initialize(PriorityQueue *PQ) {
    PQ->size = 0;
}

// 入队操作
void enqueue(PriorityQueue *PQ, Vertex v, int dist) {
    PQ->elements[PQ->size].v = v;
    PQ->elements[PQ->size].dist = dist;
    PQ->size++;
}

// 出队操作
PQNode dequeue(PriorityQueue *PQ) {
    int minDist = INT_MAX;
    int minIndex = -1;

    // 找到距离最小的节点
    for (int i = 0; i < PQ->size; i++) {
        if (PQ->elements[i].dist < minDist) {
            minDist = PQ->elements[i].dist;
            minIndex = i;
        }
    }

    // 将该节点出队
    PQNode node = PQ->elements[minIndex];
    PQ->size--;

    // 将最后一个节点移到出队位置
    PQ->elements[minIndex] = PQ->elements[PQ->size];

    return node;
}

void prim(int matrix[][NumVertex], Table T) {
    PriorityQueue PQ;
    initialize(&PQ);

    for (int i = 0; i < NumVertex; i++) {
        T[i].Known = false;
        T[i].Dist = INT_MAX;
        T[i].Path = -1;
    }

    // 随机选择一个起始顶点
    T[0].Dist = 0;
    enqueue(&PQ, 0, 0);

    while (PQ.size > 0) {
        PQNode node = dequeue(&PQ);
        Vertex v = node.v;

        T[v].Known = true;

        for (Vertex w = 0; w < NumVertex; w++) {
            if (!T[w].Known && matrix[v][w] != 0 && matrix[v][w] < T[w].Dist) {
                T[w].Dist = matrix[v][w];
                T[w].Path = v;
                enqueue(&PQ, w, matrix[v][w]);
            }
        }
    }
}

int main() {
    // 新的邻接矩阵表示的图
    int matrix[NumVertex][NumVertex] = {
        {0, 2, 4, 1, 0, 0, 0},
        {2, 0, 0, 3, 10, 0, 0},
        {4, 0, 0, 2, 0, 5, 0},
        {1, 3, 2, 0, 7, 8, 4},
        {0, 10, 0, 7, 0, 0, 6},
        {0, 0, 5, 8, 0, 0, 1},
        {0, 0, 0, 4, 6, 1, 0}
    };

    // 表格用于存储中间结果
    Table T;

    // 调用 Prim 算法
    prim(matrix, T);

    // 输出最小生成树
    printf("最小生成树:\n");
    printf("顶点\t距离\t路径\n");
    for (Vertex v = 0; v < NumVertex; v++) {
        printf("%d\t%d\t%d\n", v, T[v].Dist, T[v].Path);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 图的邻接表节点
typedef struct AdjListNode {
    int dest;   // 表示边的目标顶点，即当前节点指向的顶点
    struct AdjListNode* next;
} AdjListNode;

// 邻接表
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// 图结构
typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// 创建一个新的邻接表节点
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// 创建一个图，包含V个顶点
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// 添加一条边到图中
void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// 打印图的邻接表表示
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}






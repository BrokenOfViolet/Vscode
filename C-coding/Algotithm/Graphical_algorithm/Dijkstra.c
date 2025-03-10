#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Infinity 100000
#define NotAVertex (-1)
#define NumVertex 7

typedef int Vertex;

typedef struct AdjListNode {
    Vertex dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    AdjListNode* head;
} AdjList;

typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

typedef struct {
    bool Known;
    int Dist;
    Vertex Path;
} TableEntry;

typedef TableEntry Table[NumVertex];

// 创建一个新的邻接表节点
AdjListNode* newAdjListNode(Vertex dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// 创建一个图，V 为顶点数量
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    // 初始化邻接表头指针为空
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// 添加边到图
void addEdge(Graph* graph, Vertex src, Vertex dest, int weight) {
    // 添加从 src 到 dest 的边
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// 找到距离数组中未处理节点的最小距离
Vertex minDistance(Table T) {
    int min = Infinity, min_index = NotAVertex;

    for (int v = 0; v < NumVertex; v++) {
        if (!T[v].Known && T[v].Dist < min) {
            min = T[v].Dist;
            min_index = v;
        }
    }

    return min_index;
}

// 打印从源节点到其他所有节点的最短路径
void printSolution(Table T) {
    printf("Vertex\t Distance from Source\tPath\n");
    for (int i = 0; i < NumVertex; i++) {
        printf("\t%d\t\t%d\t\t\t\t%d\n", i, T[i].Dist,T[i].Path);
    }
}

// Dijkstra 算法
void Dijkstra(Graph* graph, Vertex src, Table T) {
    // 初始化所有距离为无穷大，Known 为 false，Path 为 NotAVertex
    for (int i = 0; i < NumVertex; i++) {
        T[i].Dist = Infinity;
        T[i].Known = false;
        T[i].Path = NotAVertex;
    }

    // 源节点的距离为 0
    T[src].Dist = 0;

    while (true) {
        // 选择距离最小的未知顶点
        Vertex V = minDistance(T);
        if (V == NotAVertex) {
            break;
        }

        // 将选定的顶点标记为已知
        T[V].Known = true;

        // 更新选定顶点的邻接顶点的距离值
        AdjListNode* pCrawl = graph->array[V].head;
        while (pCrawl != NULL) {
            Vertex W = pCrawl->dest;
            if (!T[W].Known && T[V].Dist + pCrawl->weight < T[W].Dist) {
                T[W].Dist = T[V].Dist + pCrawl->weight;
                T[W].Path = V; // 更新路径
            }
            pCrawl = pCrawl->next;
        }
    }

    // 打印最终的距离数组
    printSolution(T);
}

// 主函数
int main() {
    Graph* graph = createGraph(NumVertex);

    // 添加边
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 4, 10);
    addEdge(graph, 2, 0, 4);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 2, 2);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 3, 5, 8);
    addEdge(graph, 3, 6, 4);
    addEdge(graph, 4, 6, 6);
    addEdge(graph, 6, 5, 1);

    Table T;
    Dijkstra(graph, 0, T); // 从顶点 0 开始计算最短路径

    return 0;
}

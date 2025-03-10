#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adjacentList.h"

#define Infinity 1000000
#define NumVertex 7

typedef int Vertex;

typedef struct {
    bool Known;     // 指示顶点是否已被处理
    int Dist;       // 存储从源顶点到当前顶点的最短距离
    Vertex Path;    // 存储从源顶点到当前顶点路径上的前一个顶点的编号
} TableEntry;

typedef TableEntry Table[NumVertex];

void unweighted(Graph* graph, Table T, Vertex start) {
    for (int i = 0; i < graph->V; i++) {
        T[i].Known = false;
        T[i].Dist = Infinity;
        T[i].Path = -1;
    }

    T[start].Dist = 0;
    int CurrDist;

    for (CurrDist = 0; CurrDist < graph->V; CurrDist++) {
        for (Vertex V = 0; V < graph->V; V++) {
            if (!T[V].Known && T[V].Dist == CurrDist) {
                T[V].Known = true;
                AdjListNode* node = graph->array[V].head;
                while (node != NULL) {
                    Vertex W = node->dest;
                    if (T[W].Dist == Infinity) {
                        T[W].Dist = CurrDist + 1;
                        T[W].Path = V;
                    }
                    node = node->next;
                }
            }
        }
    }
}

void printTable(Table T, int V) {
    printf("Vertex\tDist\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\t\t%d\n", i, T[i].Dist, T[i].Path);
    }
}

int main() {
    Graph* graph = createGraph(NumVertex);
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,0);
    addEdge(graph,2,5);
    addEdge(graph,3,2);
    addEdge(graph,3,4);
    addEdge(graph,3,5);
    addEdge(graph,3,6);
    addEdge(graph,4,6);
    addEdge(graph,6,5);

    Table T;
    unweighted(graph, T, 2);
    printTable(T, NumVertex);

    return 0;
}

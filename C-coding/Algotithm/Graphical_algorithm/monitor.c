#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adjcentList.h"

#define Infinity 100000
#define NumVertex 7

typedef int Vertex;

typedef struct {
    bool Known;
    int Dist;
    Vertex Path;
} TableEntry;

typedef TableEntry Table[NumVertex];

void unweighted(Graph *graph, Table T, Vertex start)
{
    for (int i=0; i<NumVertex; i++) {
        T[i].Known = false;
        T[i].Dist = Infinity;
        T[i].Path = -1;
    }

    T[start].Dist = 0;
    for (int currDist=0; currDist < graph->V; currDist++) {
        for (Vertex i=0; i < graph->V; i++) {
            if (!T[i].Known && T[i].Dist == currDist) {
                T[i].Known = true;
                AdjListNode *node = graph->array[i].head;
                while (node) {
                    Vertex W = node->dest;
                    if (T[W].Dist == Infinity) {
                        T[W].Dist = currDist + 1;
                        T[W].Path = i;
                    }
                    node = node->next;
                }
            }
        }
    }
}

void printTable(Table T)
{
    printf("Vertex\tDist\tPath\n");
    for (int i=0; i<NumVertex; i++) {
        printf("%d\t\t%d\t\t%d\n",i,T[i].Dist,T[i].Path);
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
    printTable(T);

    return 0;
}
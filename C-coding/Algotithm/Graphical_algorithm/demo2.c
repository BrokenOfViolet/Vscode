#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
} AdjListNode;

typedef struct AdjList
{
    AdjListNode *head;
} AdjList;

typedef struct Graph
{
    int V;
    AdjList *array;
} Graph;

AdjListNode* newAdjListNode(int dest)
{
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int v)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = v;
    graph->array = (AdjList*)malloc(sizeof(AdjList)*v);
    for (int i=0; i<v; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(Graph* graph)
{
    for (int i=0; i<graph->V; ++i)
    {
        AdjListNode* pCrawl = graph->array[i].head;
        printf("\nAdjacency list of vertex %d ",i);
        while (pCrawl)
        {
            printf("-> %d",pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertex = 7;
    Graph* graph = createGraph(vertex);
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

    printGraph(graph);
    // 释放内存
    for (int v = 0; v < V; ++v) {
        AdjListNode* node = graph->array[v].head;
        while (node != NULL) {
            AdjListNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
    
    return 0;
}

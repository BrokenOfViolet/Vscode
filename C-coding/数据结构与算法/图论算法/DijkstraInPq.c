#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int vertex;
    int distance;
} Node;

typedef struct {
    Node* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->data = (Node*)malloc(capacity * sizeof(Node));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swapNode(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->data[left].distance < minHeap->data[smallest].distance)
        smallest = left;

    if (right < minHeap->size && minHeap->data[right].distance < minHeap->data[smallest].distance)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->data[smallest], &minHeap->data[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

Node extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return (Node){-1, INF};

    Node root = minHeap->data[0];
    minHeap->data[0] = minHeap->data[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(MinHeap* minHeap, int vertex, int distance) {
    int i;
    for (i = 0; i < minHeap->size; ++i) {
        if (minHeap->data[i].vertex == vertex) {
            minHeap->data[i].distance = distance;
            break;
        }
    }

    while (i && minHeap->data[i].distance < minHeap->data[(i - 1) / 2].distance) {
        swapNode(&minHeap->data[i], &minHeap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int isInMinHeap(MinHeap* minHeap, int vertex) {
    for (int i = 0; i < minHeap->size; ++i)
        if (minHeap->data[i].vertex == vertex)
            return 1;
    return 0;
}

void printArr(int dist[], int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int** graph, int V, int src) {
    int dist[V];
    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INF;
        minHeap->data[v].vertex = v;
        minHeap->data[v].distance = INF;
    }

    minHeap->data[src].vertex = src;
    minHeap->data[src].distance = 0;
    dist[src] = 0;
    minHeap->size = V;

    while (!isEmpty(minHeap)) {
        Node minNode = extractMin(minHeap);
        int u = minNode.vertex;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && isInMinHeap(minHeap, v) && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decreaseKey(minHeap, v, dist[v]);
            }
        }
    }

    printArr(dist, V);
}

int main() {
    int V = 9;
    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i)
        graph[i] = (int*)malloc(V * sizeof(int));

    int graphData[9][9] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            graph[i][j] = graphData[i][j];

    dijkstra(graph, V, 0);

    for (int i = 0; i < V; ++i)
        free(graph[i]);
    free(graph);

    return 0;
}

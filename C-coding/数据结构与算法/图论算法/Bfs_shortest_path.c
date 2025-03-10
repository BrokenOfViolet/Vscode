#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// 邻接表节点
typedef struct ListNode {
    int vertex;
    struct ListNode* next;
} ListNode;

// 图
typedef struct {
    int numVertices;
    ListNode* adjacencyList[MAX_VERTICES];
} Graph;

// 创建图
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// 添加边
void addEdge(Graph* graph, int src, int dest) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->vertex = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// 队列节点
typedef struct QueueNode {
    int vertex;
    struct QueueNode* next;
} QueueNode;

// 队列
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 创建队列
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 入队
void enqueue(Queue* queue, int vertex) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int vertex = queue->front->vertex;
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return vertex;
}

// BFS算法
void BFS(Graph* graph, int startVertex, int targetVertex) {
    bool visited[MAX_VERTICES] = {false};
    int predecessor[MAX_VERTICES] = {-1};

    Queue* queue = createQueue();
    enqueue(queue, startVertex);
    visited[startVertex] = true;

    while (queue->front != NULL) {
        int currentVertex = dequeue(queue);
        ListNode* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int neighborVertex = temp->vertex;
            if (!visited[neighborVertex]) {
                enqueue(queue, neighborVertex);
                visited[neighborVertex] = true;
                predecessor[neighborVertex] = currentVertex;
            }
            temp = temp->next;
        }
    }

    printf("Shortest path from %d to %d: ", startVertex, targetVertex);
    int currentVertex = targetVertex;
    while (currentVertex != -1) {
        printf("%d ", currentVertex);
        currentVertex = predecessor[currentVertex];
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    BFS(graph, 0, 5);

    return 0;
}

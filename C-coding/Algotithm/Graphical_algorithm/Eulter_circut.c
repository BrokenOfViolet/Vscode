#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];         // 邻接矩阵表示的图
int degree[MAX];             // 度数组，存储每个顶点的度数
int circuit[MAX * MAX];      // 欧拉回路数组
int circuitIndex;            // 欧拉回路数组的当前索引

void findEulerianCircuit(int n) {
    int currentPath[MAX * MAX]; // 路径栈
    int currentPathIndex = 0;   // 路径栈的当前索引
    int currentVertex = 0;      // 当前顶点

    currentPath[currentPathIndex++] = currentVertex; // 将起点压入路径栈

    while (currentPathIndex > 0) {
        if (degree[currentVertex] > 0) { // 当前顶点还有未访问的边
            currentPath[currentPathIndex++] = currentVertex; // 当前顶点压入路径栈
            for (int v = 0; v < n; v++) {
                if (graph[currentVertex][v]) { // 找到一条未访问的边
                    graph[currentVertex][v]--; // 移除该边
                    graph[v][currentVertex]--;
                    degree[currentVertex]--;   // 更新度数
                    degree[v]--;
                    currentVertex = v;         // 移动到相邻顶点
                    break;
                }
            }
        } else { // 当前顶点没有未访问的边
            circuit[circuitIndex++] = currentVertex; // 将当前顶点添加到欧拉回路中
            currentVertex = currentPath[--currentPathIndex]; // 回退到路径栈的前一个顶点
        }
    }
}

void printCircuit() {
    printf("Eulerian Circuit: ");
    for (int i = circuitIndex - 1; i >= 0; i--) {
        printf("%d ", circuit[i]);
    }
    printf("\n");
}

bool isEulerian(int n) {
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 5; // 图中节点数

    // 初始化图的邻接矩阵和度数
    int adjMatrix[MAX][MAX] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    for (int i = 0; i < n; i++) {
        degree[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = adjMatrix[i][j];
            degree[i] += adjMatrix[i][j];
        }
    }

    if (isEulerian(n)) {
        circuitIndex = 0;
        findEulerianCircuit(n);
        printCircuit();
    } else {
        printf("The graph does not have an Eulerian Circuit.\n");
    }

    return 0;
}

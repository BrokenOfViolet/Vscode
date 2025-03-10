#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// 使用BFS寻找增广路径，并返回是否存在增广路径
bool bfs(int rGraph[MAX][MAX], int s, int t, int parent[], int n) {
    bool visited[MAX];
    memset(visited, 0, sizeof(visited));
    
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
                
                if (v == t) return true;
            }
        }
    }

    return false;
}

// 埃德蒙兹-卡普算法实现
int edmondsKarp(int graph[MAX][MAX], int s, int t, int n) {
    int rGraph[MAX][MAX];
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[MAX];
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent, n)) {
        int pathFlow = INT_MAX;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < rGraph[u][v]) ? pathFlow : rGraph[u][v];
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n = 6; // 图中节点数
    int graph[MAX][MAX] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int s = 0, t = 5;
    printf("The maximum possible flow is %d\n", edmondsKarp(graph, s, t, n));

    return 0;
}

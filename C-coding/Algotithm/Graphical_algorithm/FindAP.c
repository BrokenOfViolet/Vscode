#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// 发现时间数组，记录每个节点被发现的时间
int disc[MAX];

// 最早回溯时间数组，记录每个节点能回溯到的最早的发现时间
int low[MAX];

// 父节点数组，记录每个节点在DFS树中的父节点
int parent[MAX];

// 访问标记数组，记录每个节点是否被访问过
bool visited[MAX];

// 割点标记数组，记录每个节点是否是割点
bool ap[MAX];

// 全局时间戳变量
int time = 0;

// 深度优先搜索（DFS）函数
void dfs(int u, int graph[MAX][MAX], int n) {
    // 子节点计数器
    int children = 0;
    
    // 标记当前节点为已访问
    visited[u] = true;
    
    // 设置发现时间和最早回溯时间
    disc[u] = low[u] = ++time;

    // 遍历所有节点，检查与当前节点u的连接
    for (int v = 0; v < n; v++) {
        if (graph[u][v]) { // 如果u和v之间有边
            if (!visited[v]) { // 如果v未被访问
                children++;
                parent[v] = u; // 设置v的父节点为u
                dfs(v, graph, n); // 递归调用DFS

                // 更新当前节点u的最早回溯时间
                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                // 如果u是根节点，且有两个或更多子节点，则u是割点
                if (parent[u] == -1 && children > 1) {
                    ap[u] = true;
                }

                // 如果u不是根节点，且满足low[v] >= disc[u]，则u是割点
                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            } else if (v != parent[u]) { // 如果v被访问过且v不是u的父节点
                // 更新当前节点u的最早回溯时间
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

// 查找图中的所有割点
void findAP(int graph[MAX][MAX], int n) {
    // 初始化所有辅助数组和变量
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        visited[i] = false;
        ap[i] = false;
    }

    // 对每个未访问的节点调用DFS
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, n);
        }
    }

    // 输出所有割点
    printf("Articulation points in the graph are: ");
    for (int i = 0; i < n; i++) {
        if (ap[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n = 7; // 图中节点数
    // 使用邻接矩阵表示的图
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0},
        {0, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };

    // 查找并输出图中的所有割点
    findAP(graph, n);

    return 0;
}

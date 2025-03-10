#include <iostream>
#include <vector>
#include <climits>

#define V 5  // 图中的顶点数

using namespace std;

struct Edge {
    int src, dest, weight;
};

void selectionSort(vector<Edge>& edges) {
    int E = edges.size();
    for (int i = 0; i < E - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < E; j++) {
            if (edges[j].weight < edges[minIndex].weight) {
                minIndex = j;
            }
        }
        swap(edges[i], edges[minIndex]);
    }
}

int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    }
    return findParent(parent, parent[vertex]);
}

bool hasCycle(int parent[], int src, int dest) {
    int srcParent = findParent(parent, src);
    int destParent = findParent(parent, dest);

    if (srcParent == destParent) {
        return true;
    }

    // Union operation
    parent[srcParent] = destParent;
    return false;
}

void KruskalMST(int graph[V][V]) {
    vector<Edge> edges;

    // 提取邻接矩阵中的所有边
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {  // 确保每条边只处理一次
            if (graph[i][j] != 0) {
                Edge edge = {i, j, graph[i][j]};
                edges.push_back(edge);
            }
        }
    }

    // 手动排序所有边
    selectionSort(edges);

    Edge result[V];  // 存储最小生成树
    int resultIndex = 0;

    // 初始化父节点数组
    int parent[V];
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < edges.size() && resultIndex < V - 1; ++i) {
        Edge nextEdge = edges[i];

        if (!hasCycle(parent, nextEdge.src, nextEdge.dest)) {
            result[resultIndex++] = nextEdge;
        }
    }

    // 打印最小生成树
    cout << "边   权重\n";
    for (int i = 0; i < resultIndex; ++i) {
        cout << result[i].src << " - " << result[i].dest << "    " << result[i].weight << "\n";
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    KruskalMST(graph);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 边的结构
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 并查集类
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

// Kruskal算法
vector<Edge> kruskal(int n, vector<Edge>& edges) {
    vector<Edge> mst; // 存储最小生成树的边
    UnionFind uf(n);
    sort(edges.begin(), edges.end());

    for (const auto& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v);
            mst.push_back(edge);
            if (mst.size() == n - 1) {
                break;
            }
        }
    }

    return mst;
}

int main() {
    int n = 4; // 顶点数
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> mst = kruskal(n, edges);

    cout << "最小生成树的边:" << endl;
    for (const auto& edge : mst) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <climits> // for INT_MAX

using namespace std;

// Function to find the vertex with the minimum distance value
int minIndex(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to implement Dijkstra's single source shortest path algorithm
void dijkstra(const vector<vector<int> >& graph, int src, int dest, int V) {
    vector<int> dist(V, INT_MAX); // The output array. dist[i] will hold the shortest distance from src to i
    vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in shortest path tree

    dist[src] = 0; // Distance of source vertex from itself is always 0

    for (int count = 0; count < V - 1; count++) {
        int u = minIndex(dist, sptSet, V);

        sptSet[u] = true; // Mark the picked vertex as processed

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Shortest distance from " << src << " to " << dest << " is " << (dist[dest] == INT_MAX ? -1 : dist[dest]) << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > graph(n, vector<int>(n, -1));
    int u, v, w = 0;
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        dijkstra(graph, u, v, n);
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v, int w);
    int minDistance(vector<int>& dist, vector<bool>& visited);
    vector<int> dijkstra(int src,vector<int>& prev);
    void printSolution(vector<int> dist);
    void printPath(int src,int dest,vector<int> prev);

private:
    int numVertices;
    vector<vector<int> > AdjMatrix;
};

Graph::Graph(int vertices) : numVertices(vertices) {
    AdjMatrix.resize(numVertices, vector<int>(numVertices, INF)); // 初始化邻接矩阵，距离初始化为INF
}

void Graph::addEdge(int u, int v, int w) {
    AdjMatrix[u][v] = w;
}

int Graph::minDistance(vector<int>& dist, vector<bool>& visited) {
    int minDist = INF, minIndex;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

vector<int> Graph::dijkstra(int src,vector<int>& prev) {
    vector<int> dist(numVertices, INF);
    vector<bool> visited(numVertices, false);

    dist[src] = 0;
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v]  && dist[u] != INF && dist[u] + AdjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + AdjMatrix[u][v];
                prev[v] = u;
            }
        }
    }
    return dist;
}

void Graph::printSolution(vector<int> dist) {
    cout << "Vertex\tDistance from source" << endl;
    for (int i = 0; i < numVertices; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

void Graph::printPath(int src,int dest,vector<int> prev) {
    if (src == dest) {
        cout << src << " ";
        return;
    }
    printPath(src,prev[dest],prev);
    cout << dest << " ";
}

int main() {
    Graph graph(7);
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 4, 3);
    graph.addEdge(1, 6, 1);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 0, 2);
    graph.addEdge(3, 5, 6);
    graph.addEdge(4, 3, 2);
    graph.addEdge(4, 5, 1);
    graph.addEdge(6, 4, 1);

    vector<int> prev(7,-1);

    int src = 0;
    vector<int> shortestPath = graph.dijkstra(src,prev);
    cout << "vertex\tdistance from source" << "\tpath" << endl;
    for (int i=1; i<7; i++) {
        cout << i << "\t\t\t\t" << shortestPath[i] << "\t\t\t\t";
        graph.printPath(src,i,prev);
        cout << endl;
    }
    return 0;
}

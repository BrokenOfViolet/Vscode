#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int src,int dest);
    void Dfs(int vertex,stack<int>& s);
    void TopLogicalSort();
private:
    int numVertices;
    vector<vector<int> > AdjLists;
    vector<bool> visited;
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    AdjLists.resize(numVertices);
    visited.resize(numVertices,false);
}

void Graph::Dfs(int vertex,stack<int>& s) {
    visited[vertex] = true;
    for (int AdjVertex : AdjLists[vertex]) {
        if (!visited[AdjVertex])
            Dfs(AdjVertex,s);
    }
    s.push(vertex);
}

void Graph::TopLogicalSort() {
    stack<int> Stack;
    Dfs(0,Stack);
    cout << "Toplogical Sort:" << endl;
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

void Graph::addEdge(int src, int dest) {
    AdjLists[src].push_back(dest);
}

int main()
{
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);

    graph.TopLogicalSort();
    return 0;
}
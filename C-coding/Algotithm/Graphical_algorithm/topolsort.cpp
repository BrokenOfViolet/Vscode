#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int src,int dest);
    void toplogicalSort();
private:
    int numVertices;
    vector<vector<int> > AdjLists;
    vector<int> indegree;
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    AdjLists.resize(numVertices);
    indegree.resize(numVertices,0);
}

void Graph::addEdge(int src,int dest) {
    AdjLists[src].push_back(dest);
    indegree[dest]++;
}

void Graph::toplogicalSort() {
    queue<int> q;
    for (int i=0; i<numVertices; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    vector<int> topOrder;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        topOrder.push_back(current);
        for (int AdjVertex : AdjLists[current]) {
            indegree[AdjVertex]--;
            if (indegree[AdjVertex] == 0)
                q.push(AdjVertex);
        }
        count++;
    }
    if (count != numVertices)
        cout << "Graph has a cycle" << endl;
    else {
        cout << "Topol sort:" << endl;
        for (int v : topOrder)
            cout << v << " ";
    }
}

int main()
{
    Graph graph(11);
    graph.addEdge(0,1);    graph.addEdge(0,4);    graph.addEdge(0,7);
    graph.addEdge(1,2);    graph.addEdge(1,5);    graph.addEdge(2,3);
    graph.addEdge(3,10);    graph.addEdge(4,1);    graph.addEdge(4,5);
    graph.addEdge(5,3);    graph.addEdge(5,6);    graph.addEdge(5,9);
    graph.addEdge(6,3);    graph.addEdge(6,10);    graph.addEdge(7,5);
    graph.addEdge(7,8);    graph.addEdge(7,4);    graph.addEdge(8,5);
    graph.addEdge(8,9);    graph.addEdge(9,6);  graph.addEdge(9,10);

    graph.toplogicalSort();
    return 0;
}
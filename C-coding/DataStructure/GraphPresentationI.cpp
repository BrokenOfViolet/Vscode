#include <iostream>

using namespace std;
// 图(graph) a graph G is an order pair of a set V of vertices and a set G of edges
// G = (V,E)    V = {v1,v2,...vn}     G = {(v1,v2),(v1,v3),...}
// 分为 directed and undirected 两种
// 在directed中，G的表示是有方向的，例如（v1,v2)表示从v1指向v2
// weighted and unweighted 加权图和无加权的图
// more attributes: self-loop : 自环，自己指向自己
// multiedges: 两点间有多条边
// number of edges: undirected:  0 <= E <= n(n-1)/2
//                  directed: 0 <= E <= n(n-1)
// path:一系列相邻接的点（connect by one edge)
// simple path(or trail): a path in which no vertice is repeated
// strongly connected graph: is there's a path from any vertice to any vertice
// Acyclic graph(无环图): a graph with no cycle
// part1: 边列表
// part2: 邻接矩阵
// part3: 邻接表

#define N 8

int main()
{
    char vertices[N] = {'A','B','C','D','E','F','G','H'};
    for (int i=0; i<N; i++)
    {
        cout << *(vertices+i) << ' ';
    }
    return 0;
}
#include <iostream>
using namespace std;

template<class InfoType>
class AdjNode
{
public:
    int another_vertex;
    InfoType info;
    AdjNode* next;
};

template<class EType,class InfoType>
class AdjList
{
public:
    EType data;
    AdjNode<InfoType> *head;
};

template<class Etype,class InfoType>
class AdjGraph
{
private:
    AdjList<EType,InfoType> *head_list;
    int vertex_num;
    int edge_num;
public:
    AdjGraph() {}
    void CreateGraph() {}
}
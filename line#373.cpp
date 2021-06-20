#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src, desc, weight;
};

class Graph
{
public:
    int V, E;
    Edge *edge;
};

Graph *create_graph(int V, int E)
{
    Graph *graph = new Graph();
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E * sizeof(Edge)];
    return graph;
}
int find(int parent[], int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return find(parent, parent[i]);
}
void Union(int u, int v, int parent[])
{
    parent[u] = v;
}
bool isCycle(Graph *graph)
{
    int *parent = new int[graph->V * sizeof(int)];
    memset(parent, -1, sizeof(int) * graph->V);
    for (int i = 0; i < graph->E; i++)
    {
        int u = find(parent, graph->edge[i].src);
        int v = find(parent, graph->edge[i].desc);
        if (u == v)
            return true;
        else
        {
            Union(u, v, parent);
        }
    }
    return false;
}
int main()
{
    int V = 3, E = 3;
    Graph *graph = create_graph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].desc = 1;
    

    graph->edge[1].src = 1;
    graph->edge[1].desc = 2;

    graph->edge[2].src = 0;
    graph->edge[2].desc = 2;

    if (isCycle(graph))
    {
        cout << "Cycle found";
    }
    else
    {
        cout << "No cycle";
    }
}
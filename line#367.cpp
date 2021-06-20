#include <bits/stdc++.h>
using namespace std;
#define V 9
int findMin(int dist[], bool setStr[V])
{
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++)
    {
        if (setStr[i] == false && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void print_dist(int dist[])
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}
void shortest_path(int graph[V][V], int src)
{
    bool setStr[V];
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        setStr[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMin(dist, setStr);
        setStr[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (dist[u] != INT_MAX && !setStr[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print_dist(dist);
}
int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    shortest_path(graph, 0);
}
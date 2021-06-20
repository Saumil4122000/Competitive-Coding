#include <bits/stdc++.h>
using namespace std;
// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int>> make_graph(int numTasks,
                                      vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}

// A DFS based function to check if there is a cycle
// in the directed graph.
bool dfs_cycle(vector<unordered_set<int>> &adj, int src,
               vector<bool> &order, vector<bool> &visited)
{
    order[src] = 1;
    visited[src] = 1;
    for (auto i : adj[src])
    {
        if (!visited[i])
        {
            bool c = dfs_cycle(adj, i, order, visited);
            if (c == true)
            {
                return true;
            }
        }
        else if (order[i])
        {
            return true;
        }
    }
    order[src] = 0;
    return false;
}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int>> &prerequisites)
{
    vector<unordered_set<int>> graph = make_graph(numTasks, prerequisites);
    vector<bool> onpath(numTasks, false), visited(numTasks, false);
    for (int i = 0; i < numTasks; i++)
        if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            return false;
    return true;
}

int main()
{
    int numTasks = 4;

    vector<pair<int, int>> prerequisites;

    // for prerequisites: [[1, 0], [2, 1], [3, 2]]

    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    prerequisites.push_back(make_pair(2, 3));
    if (canFinish(numTasks, prerequisites))
    {
        cout << "Possible to finish all tasks";
    }
    else
    {
        cout << "Impossible to finish all tasks";
    }

    return 0;
}

// In this we have given tasks  pairs  .. is there is cycle in the dependency then task completion is not possible

// pair [1,0] means to complete task1 task 0 need to be completed

// we need to apply cycle detection algo
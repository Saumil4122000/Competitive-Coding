#include <bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> &visit, vector<int> g[])
{
    visit[src] = 1;
    for (auto i : g[src])
    {
        // visit all vertex from src which are reachable so make it visited
        if (!visit[i])
        {
            dfs(i, visit, g);
        }
    }
}

int makeConnected(int n, vector<vector<int>> &connections)
{

    int m = connections.size();
    if (m < n - 1)
        return -1;
    vector<int> g[n];
    vector<int> visit(n, 0);
    int c = 0;

    // Here to find min cable to connectt all the circuits then first we have to find no of components
    //  If we find no of component then min no of edge required to make component connected = noofcomponent-1

    // MAking Graph
    for (int i = 0; i < m; i++)
    {
        g[connections[i][0]].push_back(connections[i][1]);
        g[connections[i][1]].push_back(connections[i][0]);
    }


    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            c++;
            // increment component count
            // If we found vertex which is unvisited then we call method which make that vertex and all its nodes which are reachable to its makes it true
            dfs(i, visit, g);
            //  i is src 
            // g is graph
        }
    }
    return c - 1;
}
int main()
{
    int n;
    // No of cables available
    cin >> n;
    int m;
    // No of connections available between the computer
    cin>>m;
    vector<vector<int>> connection(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {

            cin >> connection[i][j];
        }
    }
    int ans=makeConnected(n,connection);
    cout<<ans;
}
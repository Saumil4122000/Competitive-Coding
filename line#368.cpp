#include <bits/stdc++.h>
using namespace std;


void tropological_sort(int V,vector<int> adj[]){
    queue<int> q;
    vector<int> ans;
    vector<int> indegree(V,0);
    for (int i = 0; i < V; i++)
    {
        for (auto j: adj[i])
        {
            indegree[j]++;
        }
        
    }
    
    for (int i = 0; i < V; i++)
    {
        if(indegree[i]==0){
           q.push(i);
        }
    }
    
    while (!q.empty())
    {
       int i=q.front();
       q.pop();
       ans.push_back(i);
       for (auto j:adj[i])
       {
           indegree[j]--;
           if(indegree[j]==0){
               q.push(j);
           }
       }
       
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<"\t";
    }
    
}
int main()
{
    int E, N;
    cin >> E >> N;
     int u, v;
    vector<int> adj[N];
    for (int i = 0; i < E; i++)
    {
       
        cin >> u >> v;
        adj[u].push_back(v);
    }
    tropological_sort(N, adj);
}
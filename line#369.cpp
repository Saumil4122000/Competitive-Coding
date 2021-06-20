#include<bits/stdc++.h>
using namespace std;
void no_of_time_job(vector<int> adj[],int V){
    queue<int> q;
    vector<int> job(V,0);
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
           job[i]=1;
        }
    }
    
    while (!q.empty())
    {
       int i=q.front();
       q.pop();
     
       for (auto j:adj[i])
       {
           indegree[j]--;
           if(indegree[j]==0){
               job[j]=job[i]+1;
               q.push(j);
           }
       }
       
    }

    for (int i = 0; i < V; i++)
    {
        cout<<job[i]<<"\t";
    }
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    no_of_time_job(adj,V);  
}
#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<int> &order,vector<int> &visited,vector<int> adj[],int src){
    order[src]=1;
    visited[src]=1;
    for (auto i:adj[src])
    {   
        if(!visited[i]){
            bool c=isCycle(order,visited,adj,i);
            if(c==true){
                return true;
            }
        }
        else if(order[i]){
            return true;
        }
    }
    order[src]=0;
    return false;

}

bool isCycleUtil(vector<int> adj[],int n){

    vector<int> order(n,0);
    vector<int> visited(n,0);
    for (int i = 0; i < n; i++)
    {
        bool c=isCycle(order,visited,adj,i);
        if(c==true){
            return true;
        }
    }
    return false;
    
}
int main(){
//    E is no of edges
//    V is no of vertex
    int E,V;
    cin>>E>>V;
     vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }
    bool ans=isCycleUtil(adj,V);  
    cout<<ans; 
}
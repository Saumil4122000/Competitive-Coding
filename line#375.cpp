#include <bits/stdc++.h>
using namespace std;
// If a graph is a complete graph with n vertices, then total number of spanning trees is n(n-2) where n is the number of nodes in the graph. In complete graph, the task is equal to counting different labeled trees with n nodes for which have Cayley’s formula.

// What if graph is not complete?
// Follow the given procedure :-
// STEP 1: Create Adjacency Matrix for the given graph.
// STEP 2: Replace all the diagonal elements with the degree of nodes. For eg. element at (1,1) position of adjacency matrix will be replaced by the degree of node 1, element at (2,2) position of adjacency matrix will be replaced by the degree of node 2, and so on.
// STEP 3: Replace all non-diagonal 1’s with -1.
// STEP 4: Calculate co-factor for any element.
// STEP 5: The cofactor that you get is the total number of spanning tree for that graph.
void no_of_spannig_tree_incomplete_graph(int adj[4][4]){
    int mat[4];
    for (int i = 0; i < 4; i++)
    {
        int c=0;
        for (int j = 0; j < 4; j++)
        {
            if(adj[i][j]!=0){
                c++;
            }
        }
        mat[i]=c;
    }
     for (int i = 0; i < 4; i++)
    {
        int c=0;
        for (int j = 0; j < 4; j++)
        {
            if(i==j){
                adj[i][j]=mat[i];
            }
            else{
                if(adj[i][j]==1){
                    adj[i][j]=-1;
                }
            }
        }
      
    }
    
}
int main()
{
    int adj[][] = {{0, 0, 1, 1},
                   {0, 0, 1, 1},
                   {1, 1, 0, 1},
                   {1, 1, 1, 0}};
    no_of_spannig_tree_incomplete_graph(adj);
}
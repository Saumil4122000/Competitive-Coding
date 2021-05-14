#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[m],b[n];
    unordered_set<int> set;
    for (int i = 0; i < m; i++)
    {   cin>>a[i];
      
    }
    
       for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

  for(int i=0;i<n;i++){
            set.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            set.insert(b[i]);
        }

    cout<<set.size();
    return 1;
}
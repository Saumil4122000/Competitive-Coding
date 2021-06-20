#include<bits/stdc++.h>
using namespace std;
int main(){
    int w,h,n;
    cin>>w>>h>>n;
    vector<int> a;
    vector<int> b;
    a.push_back(0);
    b.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    a.push_back(w+1);
    b.push_back(h+1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int mx=0,my=0;
    for (int i = 0; i < a.size()-1; i++)
    {
        mx=max(a[i+1]-a[i]-1,mx);
        my=max(b[i+1]-b[i]-1,my);   
    }
    cout<<mx*my;   
}




// See description of problem
// pls see the video for clarity
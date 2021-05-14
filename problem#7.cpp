#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dp[n];
    int arr[n];
    int max=arr[0];
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];
    }
    dp[0]=arr[0];
    for (int i = 1; i < n; i++)
    {
       dp[i]=std::max(dp[i-1]+arr[i],arr[i]);
        max=std::max(max,dp[i]);
    }
    cout<<max;
    
}
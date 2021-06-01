#include <bits/stdc++.h>
using namespace std;
class Item
{
public:
    int value;
    int weight;
};
double fractional_Knapsack(Item arr[],int n,int W)
{
    vector<pair<double,int>> vec;
    for (int i = 0; i < n; i++)
    {
       double ratio=(arr[i].value*1.0)/(arr[i].weight*1.0);
       vec.push_back({ratio,i});
    }
    sort(vec.begin(),vec.end(),greater<pair<double,int>>() );
    int s=0;
    double values=0;
    for (int i = 0; i < n; i++)
    {
        if(s+arr[vec[i].second].weight <W){
            s+=arr[vec[i].second].weight;
            values+=arr[vec[i].second].value;
        }else{
            int remaining_weight=(W-s)*1.0;
            values+=vec[i].first * remaining_weight;
            break;
        }
    }
    return values;
}

int main()
{
    int n;
    cin >> n;
    Item arr[n];
    int W;
    cin >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].weight;
        cin >> arr[i].value;
    }
    double ans=fractional_Knapsack(arr,n,W);
    cout<<ans;
}
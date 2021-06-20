#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<pair <int,int>> buy;
    vector<pair<int,int>> sell;

    for (int i = 0; i < n; i++)
    {
        if(a[i]>0){
            buy.push_back({a[i],i});
        }
        else{
            sell.push_back({a[i],i});
        }
    }
    int i=0,j=0;
    int cost=0;
    while (i<buy.size() &&j<sell.size())
    {
        int x=min(buy[i].first,-sell[j].first);
        buy[i].first-=x;
        sell[j].first+=x;
        cost+=x*abs(buy[i].second-sell[j].second);
        if(buy[i].first==0) i++;
        if(sell[j].first==0) j++;
    }
    cout<<cost;
}



// Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city. Every day each inhabitant decides how much wine he wants to buy or sell. Interestingly, demand and supply is always the same, so that each inhabitant gets what he wants.
// 
// There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good, the inhabitants of Gergovia don't care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.
// 
// In this problem you are asked to reconstruct the trading during one day in Gergovia. For simplicity we will assume that the houses are built along a straight line with equal distance between adjacent houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work.

// here given arr=[5,-4,1,-3,1]

// negetive represent sell
// here we store buy item in buy vector with index

// like vec= ({5,0}{1,2},{1,4})
// like sell=({-4,1},{-3,3})
// we store the index to calcilate the cost
// buy we want 5 but in sell we have  4 so first buy 4 and cost is 4*(1-0)=4
// we still need 1 so inc j++ and get 1 from -3 part and decrement it to -2
// so that cost is (0-3)=3*1;
// Cost for first buy is=3+4=7
// now i++
// take 1 from sell so sell=({0.1},{-2,3}) after({0.1},{-1,3})
// so cost=7+abs(2-3)=8
// now i++
// buy 1 from remainig sell 
// cost=8+abs(4-3)*1=9
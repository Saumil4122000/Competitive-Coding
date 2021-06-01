#include<bits/stdc++.h>
using namespace std;
int max_no_of_stock_buy(int price[],int k,int n){
    vector<pair<int,int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(make_pair(price[i],i+1));
    }

/**
 *  vec={[10,1],[7,2],[19,3]}
 * first is price of stock on ith day and second is day number
 * we can buy i no of stock on ith day suppose on day 1 i can buy 1 stock
 * k=Total Money
 * n=number of day
 * min(vec[i].second,(k / vec[i].first)) It represent no of stock i can buy on ith day
 * suppose on first day i can buy(1,45/10)=min(1,4.5)=(1,4)=1
 *  
 * it is used when (k / vec[i].first) we don;t have enogh money to buy more stock 
 * 
 * Day=2 (2,35/14)=(2,2)=2
 * 
 * 
 * suppose on day=3 i have money=45-10-14=21
 * now on day 3 i can't buy all the stocks min(3,21/19)=min(3,1)=1 so that's why this condition is here and final ans will be
 * 1st day=1
 * 2nd day=2;
 * 3rd day=1 total=4
 * 
 * **/


    int count=0;
    for (int i = 0; i < n; i++)
    {
        count+=min(vec[i].second,(k / vec[i].first));
        k-=vec[i].first*min(vec[i].second,(k / vec[i].first));
        // deducting stocks price from total money
        // vec[i].first=price of 1 stock
        // min(vec[i].second,(k / vec[i].first)) no of stock 
    }
    return count;
    
}
int main(){
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
    int c=max_no_of_stock_buy(price,k,n);
    cout<<c;
}
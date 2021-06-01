#include<bits/stdc++.h>
using namespace std;
void max_sum_after_k_negation(int a[],int n,int k){
    int mini=INT_MAX;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]<0){
            a[i]=-a[i];
            k--;
        }
        mini=min(mini,a[i]);
        sum+=a[i];
    }

    if(k!=0 && k%2!=0){
        sum=sum-2*mini;
    }
    cout<<sum;
}
int main(){
    int a[]={5, -2, 5, -4, 5, -12, 5, 5, 5, 20};
    int n=sizeof(a)/sizeof(a[0]);
    int k=5;
    max_sum_after_k_negation(a,n,k);
}
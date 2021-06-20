#include<bits/stdc++.h>
using namespace std;
int max_sum_subset(int a[],int n){
    int halfsum=0;
    for (int i = 0; i < n; i++)
    {
        halfsum+=a[i];
    }
    sort(a,a+n,greater<>());
    // sort in reverse order
    halfsum=halfsum/2;
    int currentSum=0;
    int c=0;
    for (int i = 0; i < n; i++)
    {
        currentSum+=a[i];
        c++;
        if (currentSum>halfsum)
        {
            return c;
        }   
    }
     return c;
    
}
int main(){
    int a[]={3,1,7,1};
    int n=sizeof(a)/sizeof(a[0]);
    int number=max_sum_subset(a,n);
    cout<<number;
}
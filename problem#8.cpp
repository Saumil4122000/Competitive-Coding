#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr1[]={-5, 3, 6, 12, 15};
    int arr2[]={-12, -10, -6, -3, 4, 10};
    int i=sizeof(arr1)/sizeof(arr1[0]);
    int j=sizeof(arr2)/sizeof(arr2[0]);
    int final[i+j];
    std::copy(arr1+0,arr1+i,final);
    std::copy(arr2+0,arr2+j,final+i);
     int n=i+j;
    sort(final, final + n);
   
    for (int k = 0; k < n ; k++)
    {
      cout<<final[k]<<"\t";
    }
    
    
    if(i+j%2==0){
        int median=(final[n/2]+final[(n/2)-1])/2;
        cout<<median<<secondl;
    }
    else{
        int median=final[n/2];
        cout<<median<<secondl;
    }
}
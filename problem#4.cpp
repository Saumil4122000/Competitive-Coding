#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={0,1,2,1,1,0,1,1,2,2};
    int n=10;
    int mid=0,start=0,second=n-1;
    while(mid< second)
            {
            switch(arr[mid])
            {
            case 0: swap(arr[start],arr[mid]);
            start++; mid++;
            break;
            case 1: mid++;
            break;
            case 2: swap(arr[mid],arr[second]);
            second--; 
            break;
            }
            }   
    for (int i = 0; i < n; i++)
    {
      cout<<arr[i]<<secondl;
    }
    
    return 1;
}
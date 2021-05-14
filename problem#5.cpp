#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1];
   for (int i = 0; i < n; i++)
   {
      cin>>arr[i];
   }
   
    
    int left=0,right=n-1;
    while (left<right)
    {
        if(arr[left]<0 && arr[right]>0){
            left++;
            right--;
        }
        else if(arr[left]>0 && arr[right]<0){
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
        else if(arr[left]>0 && arr[right]>0){
            right--;
        }
        else{
            left++;
        }
    }
      for (int i = 0; i < n; i++)
   {
      cout<<arr[i]<<"\t";
   }
   
}
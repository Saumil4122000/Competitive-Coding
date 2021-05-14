#include <bits/stdc++.h>
using namespace std;
void  reverseArray(int arr[],int start,int second){
      if(start>second)
        return;
    else{
        while (start<second)
        {
           int temp=arr[start];
           arr[start]=arr[second];
           arr[second]=temp;
           start++;
           second--;
        }
        
    }
    
}

// void  reverseArray(int arr[],int start,int second){
//       if(start>second)
//         return;
//     else{
//        
//            int temp=arr[start];
//            arr[start]=arr[second];
//            arr[second]=temp;
//           reverseArray(arr,++start,--second);
//        
        
//     }
    
// }
void printarray(int arr[],int n){
    for (int i = 0; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }

}


int main(){
    int n;
    cout<<"Enter the size of array"<<secondl;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter "<<i+1;
       cin>>arr[i];
    }
    cout<<"Normal array";
    printarray(arr,n-1);
    cout<<secondl;
    reverseArray(arr,0,n-1);
    cout<<"Reverse Array"<<secondl;
     printarray(arr,n-1);

}

#include<bits/stdc++.h>
using namespace std;
bool  product_to_X(int a[],int x,int n){

    unordered_set<int> s;
    if (n<2)
    {
       return false;
    }
    list<int> l;
    for (int i = 0; i < n; i++)
    {
       if (a[i]==0)
       {
           if(x==0){
               return true;
           }
           else{
               continue;
           }
       }
     if (x%a[i]==0)
     {
       
        if (s.find(x/a[i])!=s.second())
        {
            l.push_back(a[i]);
            l.push_back(x/a[i]);
            for (list<int>::iterator i = l.begin(); i !=l.second(); i++)
            {
               cout<<*i<<" "<<secondl;
            }
            
            return true;
        }
        s.insert(a[i]);
     }
       
       
    }
    
    return false;
}
int main(){
    int a[]={10,20,9,40};
    int x=180;
    int n=sizeof(a)/sizeof(a[0]);
    bool ans=product_to_X(a,x,n);
    cout<<ans;
 
    return 1;
}
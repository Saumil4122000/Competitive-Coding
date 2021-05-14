#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int start=0,second=1;
    int l,h;
    for (int i = 1; i < s.length(); i++)
    {
       l=i-1;
       h=i;
       while (l>=0 && h <s.length() && s[l]==s[h])
       {
          if(h-l+1>second){
              start=l;
              second=h-l+1;
          }
          l--;
          h++;
       }

    }
    string str=s.substr(start,start+second-1);
    cout<<str<<secondl;
}
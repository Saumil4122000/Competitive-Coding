#include<bits/stdc++.h>
using namespace std;
void shuffel_check(string s1,string s2,string sub){
    int i=0,j=0,k=0;
    if (s1.length()+s2.length()!=sub.length())
    {
        cout<<"NOT A SHUFFLE OF TWO STRING";
    }
    else{
        while (k!=sub.length())
        {
           if (s1.at(i)==sub.at(k) && i<s1.length())
           {
              i++;
           }
           else if (s2.at(j)==sub.at(k) && j<s2.length())
           {
              j++;
           }
           else{
              cout<<"NOT A SHUFFLE OF TWO STRING";   
           }
           k++;
        }
    }
        if (i<s1.length() || j<s2.length())
        {
            cout<<"NOT A SHUFFEL OF TWO STRING";
        }
        else{
            cout<<"IT IS SHUFFLE OF TWO STRING";
        }
        
  
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    string sub;
    cin>>sub;
    shuffel_check(s1,s2,sub);
    return 1;
}
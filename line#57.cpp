#include<bits/stdc++.h>
using namespace std;
int palindrome(string s){
    int i=0;
    int j=s.size()-1;
    while (i<j)
    {
        if(s[i]!=s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
int main(){
    string s;
    cin>>s;
    int result=palindrome(s);
    cout<<result;
}
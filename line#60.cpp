#include<bits/stdc++.h>
using namespace std;
bool rotation_string(string main_str,string sub_str){
    string s=main_str+main_str;
    return (s.find(sub_str)!=string::npos);
}
int main(){
    string s;
    string s1;
    cin>>s>>s1;
    bool ans=rotation_string(s,s1);
    if(ans)
        cout<<"TRUE";
    else
        cout<<"FALSE";
    return 1;
}
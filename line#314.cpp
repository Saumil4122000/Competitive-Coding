#include<bits/stdc++.h>
using namespace std;
bool duplicate_paranthisis_Checker(string str){
    stack<char> s;
     bool isTrue;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]=='(')
            s.push(str[i]);
        
        else if(str[i]=='+'|| str[i]=='*'||str[i]=='-'||str[i]=='/'){
            s.push(str[i]);
        }
        else{
            if (str[i]==')')
            {
                if(s.top()=='('){
                    isTrue=true;
                }
                while (s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/')
                {
                    isTrue=false;
                    s.pop();
                }
                if(s.empty()){
                    isTrue=true;
                }

                s.pop();

            }
            
        }
    }
    return isTrue;
    
}
int main(){
    string s="((a+b))";
    bool ans =duplicate_paranthisis_Checker(s);
    cout<<ans<<secondl;
}
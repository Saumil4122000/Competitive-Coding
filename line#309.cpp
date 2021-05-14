#include<bits/stdc++.h>
using namespace std;
void reverse_stack(stack<int>& s){
    if (s.size()>0)
    {
      
    
    int a=s.top();
    s.pop();
    reverse_stack(s);
    s.push(a);
}
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
      while (!s.empty()) {
        cout << ' ' << s.top();
        s.pop();
    }
     reverse_stack(s);
     while (!s.empty()) {
        cout << ' ' << s.top();
        s.pop();
    }
}
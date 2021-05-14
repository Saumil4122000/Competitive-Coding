#include<bits/stdc++.h>
using namespace std;
void interleave_half(queue<int>& q){
    int size=q.size();
    int half_size=(size)/2;
    stack<int> s;


    // Stack:::  11 12 13 14 15(top)
    // Queue:::  16 17 18 19 20
    for (int i = 0; i < half_size; i++)
    {
       s.push(q.front());
       q.pop();
    }

    // Queue::: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
   
      // Queue:::  15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < half_size; i++)
    {
       q.push(q.front());
       q.pop();
    }
    // Stack::: 15 14 13 12 11(top)
    // Queue::: 16 17 18 19 20
     for (int i = 0; i < half_size; i++) {
        s.push(q.front());
        q.pop();
    }
  
    // stack::: 15 14 13 12 11(top)  
    // Queue:::  16 17 18 19 20
    while (!s.empty())
    {
       q.push(s.top());
       s.pop();
       q.push(q.front());
       q.pop();
    }
     
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    interleave_half(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    } 
  
}
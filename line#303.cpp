#include<bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<int> s;

void push(int item){
    if (s1.size()==0)
    {
        s1.push(item);
    }
    else{
        if (s1.top()>item)
        {
           s1.push(item);
        }
        else{
            s1.push(s1.top());
        }
        
    }
    //   print_stack(s);
    
}

void pop(){
    s1.pop();
    return s.pop();
}
int get_MIN(){
    int item= s1.top();
    s1.pop();
    return item;
}
void PrintStack(stack<int> s)
{
    // If stack is empty
    if (s.empty())
        return;
 
// Extract top of the stack
    int x = s.top();
 
    // Pop the top element
    s.pop();
 
    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';
 
    // Proceed to print
// remaining stack
    PrintStack(s);
 
    // Push the element back
    s.push(x);
}
int main(){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);
    int min=get_MIN();
    cout<<min<<secondl;

    PrintStack(s);
}
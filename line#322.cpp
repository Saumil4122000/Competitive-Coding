#include<bits/stdc++.h>
using namespace std;
void printQueue(queue<int> Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
void reverse_queue(queue<int>& q)
{
    if (!q.empty())
    {
        return;
    }
    int data=q.front();
    q.pop();
    reverse_queue(q);
    q.push(data);
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    reverse_queue(q);
    printQueue(q);
}
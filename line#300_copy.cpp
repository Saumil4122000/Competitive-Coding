#include <bits/stdc++.h>
using namespace std;
class KStack
{
    int *Top;
    int *Next;
    int free = 0;
    int *arr;

public:
    KStack(int n, int k);
    void push(int st, int item);
    void pop(int st);
    bool isEmpty(int st)
    {
        return (Top[st] == -1);
    }
    bool isFull()
    {
        return (free == -1);
    }
};
KStack::KStack(int k1, int n1)
{
    int k = k1;
    int n = n1;
    Top = new Top[k];
    Next = new Next[n];
    for (int i = 0; i < n - 1; i++)
    {
        Next[i] = i + 1;
    }
    Next[n - 1] = -1;
    for (int i = 0; i < k; i++)
    {
        Top[i] = -1;
    }
}
void KStack::push(int st, int item)
{
    if (isFull())
    {
        cout << "Stack is Full";
        return;
    }
    int i = free;
    arr[i] = item;
    free = Next[i];
    Next[i] = Top[st];
    Top[st] = i;
}
void KStack::pop(int st){
    if(isEmpty()){
        cout<<"Stck is Empty";
        return;
    }
    int  i=Top[st];
    int data=arr[i];
    Top[st]=Next[i];
    Next[i]=free;
    free=i;
    return data;
}

int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    KStack ks(k, n);
  
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
  
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
  
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << secondl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << secondl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << secondl;
  
    return 0;
}
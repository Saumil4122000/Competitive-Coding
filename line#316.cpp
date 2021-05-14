#include<bits/stdc++.h>
using namespace std;
class DoubleQueueNode{
    public:
    int data;
    DoubleQueueNode* next;
    DoubleQueueNode* prev;
};

class DQueue{
    private:
    DoubleQueueNode* head;
    DoubleQueueNode* tail;
    public:
   DQueue()
    {
        head = tail = NULL;
    }
 
     bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    void insert_begin(int x){
        DoubleQueueNode* q=new DoubleQueueNode[sizeof(DoubleQueueNode)];
        q->data=x;
        q->next=NULL;
        q->prev=NULL;
        if (head==NULL)
        {
           tail=head=q;
        }
        else{
            head->prev=q;
            q->next=head;
            head=q;
        }
        
    }
    void insert_last(int x){
        DoubleQueueNode* q=new DoubleQueueNode[sizeof(DoubleQueueNode)];
        q->data=x;
        q->next=NULL;
        q->prev=NULL;
         if (tail==NULL)
        {
           head=tail=q;
        }
        else{
            tail->next=q;
            q->prev=tail;
            tail=q;
        }
    }

    void remove_first(){
         DoubleQueueNode* q;
        if(!isEmpty){
            q=head;
            head=head->next;
            head->prev=NULL;
            q->next=NULL;
            free(q);
        }
    }
    void remove_last(){
         DoubleQueueNode* q;
        if(!isEmpty){
            q=tail;
            tail=tail->prev;
            tail->next=NULL;
            q->prev=NULL;
            free(q);
        }
    }

    int get_size(){
        DoubleQueueNode* q;
        q=head;
        int count=0;
        while (!q)
        {   
           count++;
           q=q->next;
        }
        return count;
    }
     void display()
    {
   
        if (!isEmpty()) {
            DoubleQueueNode* temp = head;
            while (temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << secondl;
            return;
        }
        cout << "List is Empty" << secondl;
    }

};


class Stack : public DQueue {
public:
    // push to push element at top of stack
    // using insert at last function of deque
    void push(int element)
    {
        insert_last(element);
    }
 
    // pop to remove element at top of stack
    // using remove at last function of deque
    void pop()
    {
        remove_last();
    }
};

class Queue : public deque {
public:
    // enqueue to insert element at last
    // using insert at last function of deque
    void enqueue(int element)
    {
        insert_last(element);
    }
 
    // dequeue to remove element from first
    // using remove at first function of deque
    void dequeue()
    {
        remove_first();
    }
};
 
 int main(){
    Stack stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    // object of Queue
    Queue que;
 
    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();
 
    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();
 
    cout << "Size of Stack is " << stk.size() << secondl;
    cout << "Size of Queue is " << que.size() << secondl;
    return 0;
 }
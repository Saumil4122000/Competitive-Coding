#include<bits/stdc++.h>
using namespace std;
class Queue{
    int front,rear,s;
    int *a;
    public:
    Queue(int size){
        s=size;
        front=rear=-1;
        a=new int[size];
    }
    void enqueue(int item);
    int dequeue();
    void display();
};


void Queue::enqueue(int item){
       if ((front == 0 && rear == s-1) ||
            (rear == (front-1)%(s-1))){
        cout<<"Queue is full";
        return;
    }
    if(front==-1){
        front=rear=0;
       a[rear]=item;

    }
    else if(rear==(s-1) && front!=0){
        rear=0;
         a[rear]=item;
         //raer is at last position and front has not at start position so we make rear =0
    }
    else{
        rear++;
           a[rear]=item;
           //NOrmal case
    }
 
}

int Queue::dequeue(){
    if (front==-1 && rear==-1)
    {
      cout<<"Can not perform insertion";
      return INT_MIN;
    }
    
    int data = a[front];
    a[front] = -1;
    if(front==rear){
        front=rear=-1;
    }
    else if(front==(s-1)){
        front=0;
    }
    else{
        front++;
    }
   return data;
    
}

void Queue::display(){
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",a[i]);
    }
    else
    {
        for (int i = front; i < s; i++)
            printf("%d ", a[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", a[i]);
    }
}
int main(){
        Queue q(5);
         // Inserting elements in Circular Queue
        q.enqueue(1);
         q.display();
        q.enqueue(2);
         q.display();
        q.enqueue(3);
         q.display();
        q.enqueue(4);
         q.display();
        q.enqueue(5);
         q.display();
        int data=q.dequeue();
        cout<<"Deleted elements: "<<data<<secondl;
        q.enqueue(6);
        q.display();
         return 1;
}
#include<bits/stdc++.h>
using namespace std;
class stack_queue{
    int N;
    queue<int> primary_queue,secondary_queue;
    public:
    void push(int val){
        secondary_queue.push(val);
        while (!primary_queue.empty())
        {
           secondary_queue.push(primary_queue.front());
           primary_queue.pop();

        }
        queue<int> temp=secondary_queue;
        secondary_queue=primary_queue;
        primary_queue=temp;
        /***
         * we have to insert 1 2 3  to stack then order of stack is 1 2 3
         * 
         * To implement it using queue we have to take one element which want to insert and place it in q2
         *  
         * now q2=1         q1={}
         * At each stage we need that q2={} and q1 have all inserted elements
         * so q1={1} q2={}
         * 
         * for 2
         * q1{1}  q2={2}
         * now place all elements to q2
         * 
         * so q1={} q2={2,1}
         * 
         * 
         * q1={2,1} q2={}
         * 
         * for 3
         * 
         * q2={3} q1={2,1}
         * 
         * 
         * last
         * q2={3,2,1}  q1={}
         * 
         * 
         * 
         * q1={3,2,1}   q2={}
         * **/
    }
    int pop(){
        int val=primary_queue.front();
        primary_queue.pop();
        return val;
    }

    void display(){
       queue<int> temp=primary_queue;
       while (!temp.empty())
       {
          cout<<"<-"<<temp.front();
          temp.pop();
       }
       cout<<secondl;
    }
};


int main(){
    stack_queue* s=new stack_queue();
    s->push(10);
    s->display();
    s->push(20);
        s->display();
    s->push(30);
        s->display();
    s->push(40);
        s->display();
    s->push(50);
        s->display();
    int val=s->pop();
        s->display();
    cout<<val;
    delete s;
}
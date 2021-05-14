#include<bits/stdc++.h>
using namespace std;
class Tnode{
    public:
    int data;
    Tnode* link;
    };

Tnode* create_node(int data){
    Tnode* node=new Tnode();
    node->data=data;
    node->link=NULL;
    return node;
}
Tnode* create_list(int n){
    int data;
    cin>>data;
    Tnode* head=create_node(data);
    Tnode* p;
    p=head;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin>>data;
        Tnode* node=create_node(data);
        p->link=node;
        p=p->link;
    }
    return head;
}
Tnode* remove_last_add_first(Tnode* head){
    Tnode* p=head;
    Tnode* prev=NULL;
    while (p && p->link!=NULL)
    {
        prev=p;
        p=p->link;
    }

    prev->link=NULL;

    p->link=head;
    head=p;
    
    return head;

}
void print_link(Tnode* head){
    Tnode* p=head;
    while ( p !=NULL)
    {
      cout<<p->data<<" ";
        p=p->link;
    }
    
}
int main(){
    int n;
    cin>>n;
    Tnode* head=create_list(n);
    Tnode* h=remove_last_add_first(head);
     print_link(h);
    return 1;
}

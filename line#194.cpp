#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
    Tree(int x){
        data=x;
        left=right=NULL;
    }
};


 void Tree_to_DLL(Tree* root,Tree** head){
     
     if(root==NULL) return;
     Tree* prev=NULL;
     Tree_to_DLL(root->left,head);

    if(prev==NULL){
        *head=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;

     Tree_to_DLL(root->right,head);
 }
 void PrintList(Tree* head){
     
     while(head!=NULL){
         cout<<head->data<<" ";
         head=head->right;
     }
 }  
int main(){
    Tree* root=new Tree(10);
    root->left=new Tree(20);
    root->right=new Tree(30);
    root->left->left=new Tree(40);
    root->left->right=new Tree(50);
    root->left->right->left=new Tree(60);

    Tree* head=NULL;
    Tree_to_DLL(root,&head);
    PrintList(head);
}
#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
    int data;
    Tree *left;
    Tree* right;
    Tree(int data){
        this->data=data;
        left=right=NULL;
    }
};

void Inorder_Traversal(Tree* root){
    stack<Tree*> s;
    Tree* curr=root;
    while (curr!=NULL || s.empty()==false)
    {
        
        while (curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }

    
}

// void Inorder_Traversal(Tree* root){
//     if(root==NULL){
//         return;
//     }
//     Inorder_Traversal(root->left);
//     cout<<root->data<<" ";
//     Inorder_Traversal(root->right);
// }

int main(){
    Tree *root=new Tree(10);
    root->left=new Tree(20);
    root->right=new Tree(30);
    root->left->left=new Tree(40);
    root->left->right=new Tree(50);
    Inorder_Traversal(root);
    return 1;
}
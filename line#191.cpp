#include<bits/stdc++.h>
using namespace std;
// Diagonal Traversal

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

void Diagonal_Traversal(Tree* root){
    queue<Tree*> q;
    q.push(root);
    while (!q.empty())
    {
        Tree* temp=q.front();
        q.pop();
        while (temp)
        {
            if(temp->left){
                q.push(temp->left);
            }
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    
    }
    
}
int main(){

    Tree* root=new Tree(8);
    root->left=new Tree(3);
    root->right=new Tree(10);
    root->left->left=new Tree(1);
    root->left->right=new Tree(6);
    root->left->right->left=new Tree(4);
    root->left->right->right=new Tree(3);
    root->right->right=new Tree(5);
    root->right->right->left=new Tree(2);
    Diagonal_Traversal(root);
    return 1;
}
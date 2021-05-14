#include <bits/stdc++.h>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void Postorder_treaversal(Tree* root){
    // stack<Tree*> s1,s2;
    // s1.push(root);
    // while(s1.empty()==false){
    //     Tree* temp=s1.top();
    //     s1.pop();
    //     s2.push(temp);
    //     if(temp->left){
    //         s1.push(temp->left);
    //     }
    //      if(temp->right){
    //         s1.push(temp->right);
    //     }
    // }
    // while(s2.empty()==false){
    //     cout<<s2.top()->data<<" ";
    //     s2.pop();
    // }
    if(root==NULL){
        return;
    }
 
    Postorder_treaversal(root->left);
       Postorder_treaversal(root->right);
    cout<<root->data <<" ";
}
int main()
{
    Tree *root = new Tree(10);
    root->left = new Tree(20);
    root->right = new Tree(30);
    root->left->left = new Tree(40);
    root->left->right = new Tree(50);
    Postorder_treaversal(root);
    return 1;
}
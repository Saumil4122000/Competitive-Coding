#include<bits/stdc++.h>
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
        this->left = this->right = 0;
    }
};
int f=0;
int Height_Balance(Tree* root){
    if(root==NULL){
        return 0;
    }
    int left=Height_Balance(root->left);
    int right=Height_Balance(root->right);
    if(abs(left-right)>1){
        f=1;
    }
    return std::max(left,right)+1;
}
int main()
{
    Tree *root = new Tree(3);
    root->left = new Tree(6);
    root->right = new Tree(5);
    root->left->right = new Tree(3);
    root->left->left = new Tree(4);

    int h=Height_Balance(root);
    if(h){
        cout<<"Balance";
    }
    else{
        cout<<"No balance";
    }
}
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

// void Preorder_treaversal(Tree* root){
//     if(root==NULL){
//         return;
//     }
//     cout<<root->data<<" ";
//     Preorder_treaversal(root->left);
//     Preorder_treaversal(root->right);

// }

void Preorder_treaversal(Tree *root)
{
    stack<Tree *> s;
    if (root == NULL)
    {
        return;
    }
    else
    {
        Tree *curr = root;
        s.push(root);
        while (s.empty() == false || !curr)
        {
            curr = s.top();
            cout << curr->data << " ";
            s.pop();
            if (curr->right)
            {
                s.push(curr->right);
              
            }
            if (curr->left)
            {
                s.push(curr->left);
                
            }
        }
    }
}
int main()
{
    Tree *root = new Tree(10);
    root->left = new Tree(20);
    root->right = new Tree(30);
    root->left->left = new Tree(40);
    root->left->right = new Tree(50);
    Preorder_treaversal(root);
    return 1;
}
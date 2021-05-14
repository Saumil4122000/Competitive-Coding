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
void Left_View(Tree *root)
{
    queue<Tree *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            Tree *temp = q.front();
            q.pop();
            if (i == 1)
            {
                cout << temp->data << " ";
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
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
    root->left->right->right = new Tree(60);
    Left_View(root);
    return 1;
}
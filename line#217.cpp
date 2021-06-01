#include <bits/stdc++.h>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
};

Tree *create_node(int data)
{
    Tree *temp = new Tree;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Tree *insert(int data, Tree *root)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    if (root->data > data)
    {
        root->left = insert(data, root->left);
    }
    else
    {
        root->right = insert(data, root->right);
    }

    return root;
}

void Predecessor_successor(Tree *root, Tree *&pred, Tree *&succ, int key)
{
    if (root == NULL)
        return;
    while (root != NULL)
    {
        if (root->data == key)
        {
            if (root->right)
            {
                succ = root->right;
                while (succ->left)
                {
                    succ = root->left;
                }
            }
            if (root->left)
            {
                pred = root->left;
                while (pred->right)
                {
                    pred = root->right;
                }
                return;
            }
        }
        else if (root->data > key)
        {
            succ = root;
            root = root->left;
        }
        else
        {
            pred = root;
            root = root->right;
        }
    }
}
int main()
{
    Tree *root = NULL;
    root = insert(50, root);
    insert(30, root);
    insert(20, root);
    insert(40, root);
    insert(70, root);
    insert(60, root);
    insert(80, root);
    Tree *pred = NULL;
    Tree *succ = NULL;
    Predecessor_successor(root, pred, succ, 65);
    if (pred != NULL)
        cout << "Predecessor is " << pred->data << endl;
    else
        cout << "No Predecessor";

    if (succ != NULL)
        cout << "Successor is " << succ->data;
    else
        cout << "No Successor";
    return 0;
}
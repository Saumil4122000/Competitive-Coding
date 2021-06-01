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
    temp->left = temp->right = NULL;
    return temp;
}

Tree *insert(int data, Tree *root)
{
    if (root == NULL)
    {
        return create_node(data);
    }
    else if (root->data > data)
    {
        root->left = insert(data, root->left);
    }
    else
    {
        root->right = insert(data, root->right);
    }
    return root;
}

bool isBSTUtil(Tree *root, Tree *&prev)
{
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
        {
            return false;
        }
        if (prev != NULL && prev->data <= root->data)
        {
            return false;
        }
        prev = root;
        return isBSTUtil(root->right, prev);
    }
    return true;
}

bool isBst(Tree *root)
{
    Tree *prev = NULL;
    return isBSTUtil(root, prev);
}

int main()
{
    Tree *root = NULL;
    root = insert(30, root);
    insert(20, root);
    insert(50, root);
    insert(10, root);
    insert(40, root);
    // insert(60, root);
    // insert(80, root);

    if (isBst(root))
    {
        cout << "Is BST";
    }
    else
    {
        cout << "NO BST";
    }
}
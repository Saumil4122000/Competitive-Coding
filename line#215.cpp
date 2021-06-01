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

Tree *findMin(Tree *root)
{
    Tree *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
void inorder_traversal(Tree *root)
{
    while (root != NULL)
    {
        inorder_traversal(root->left);
        cout << root->data;
        inorder_traversal(root->right);
    }
}

Tree *deleteNode(Tree *&root, int key)
{
    if (!root)
        return root;
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->data == key)
        {
            if (!root->left && !root->right)
            {
                return NULL;
            }
            else if (root->left == NULL)
            {
                Tree *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Tree *temp = root->left;
                free(root);
                return temp;
            }
            Tree *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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

    inorder_traversal(root);
    root=deleteNode(root,20);
    inorder_traversal(root);
    return 0;
}
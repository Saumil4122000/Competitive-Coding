#include <bits/stdc++.h>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    int height;
    Tree(int data)
    {
        this->data = data;
        this->left = this->right = 0;
    }
};
void Bottom_View(Tree *root)
{
    map<int, int> mp;
    queue<Tree *> q;
    root->height = 0;
    q.push(root);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        int hp = temp->height;

        // In Bottom view approach is same as Top View but in this approach suppose for some common height if there are two elements present then we select the element which is last in level order travsersal
        // So for that if we found the same height which already availabel in map then we just update element correspoding to that height with new element

        if (mp.count(hp) != 0)
        {
            mp[hp] = temp->data;
        }
        else
        {
            mp[hp] = temp->data;
        }
        if (temp->left)
        {
            temp->left->height = hp - 1;
            q.push(temp->left);
        }
        if (temp->right)
        {
            temp->right->height = hp + 1;
            q.push(temp->right);
        }
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        cout << i->second << " ";
    }
}

int main()
{
    Tree *root = new Tree(3);
    root->left = new Tree(6);
    root->right = new Tree(5);
    root->left->right = new Tree(3);
    root->left->left = new Tree(4);

    Bottom_View(root);
}
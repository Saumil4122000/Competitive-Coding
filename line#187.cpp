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
        left = right = NULL;
    }
};
void Top_View(Tree *root)
{
    queue<Tree *> q;
    root->height = 0;
    map<int, int> mp;
    q.push(root);
    while (!q.empty())
    {
        Tree *temp = q.front();
        int hp = temp->height;
        q.pop();
        if (mp.count(hp) == 0)
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
    Tree *root = new Tree(11);
    root->left = new Tree(23);
    root->right = new Tree(35);
    root->left->right = new Tree(47);
    root->left->right->right = new Tree(59);
    root->left->right->right->right = new Tree(68);
    Top_View(root);
    return 1;
}
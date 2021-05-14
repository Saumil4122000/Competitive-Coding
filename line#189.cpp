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
        this->left = this->right = 0;
    }
};
void Level_Order(Tree *root)
{
    queue<Tree *> q;
    q.push(root);
    int f = 1;
    vector<int> ans;
    // It is vec of final ans
    while (!q.empty())
    {
        vector<int> vec;
        int size = q.size();
        for (int i = 1; i <= size; i++)
        {
            Tree *temp = q.front();
            q.pop();
            vec.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        if (f % 2 == 0)
        {
            reverse(vec.begin(), vec.end());
        }

        for (int i = 0; i < vec.size(); i++)
        {
            ans.push_back(vec[i]);
        }
        f++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\t";
    }
}

int main()
{
    Tree *root = new Tree(3);
    root->left = new Tree(6);
    root->right = new Tree(5);
    root->left->right = new Tree(3);
    root->left->left = new Tree(4);

    Level_Order(root);
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *create_Node(int data)
{
    Node *n = new Node();
    n->data = data;
    n->right = NULL;
    n->left = NULL;

    return n;
}
bool anagram_tree1_tree2(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    queue<Node *> q1, q2;
        q1.push(root1);
        q2.push(root2);
        while (1)
        {
            vector<int> curr_level1, curr_level2;
            int n1 = q1.size();
            int n2 = q2.size();
            if (n1 != n2)
            {
                return false;
            }
            if (n1 == 0)
            {
                break;
            }
            while (n1 > 0)
            {
               Node* node1=q1.front();
               q1.pop();
               if (node1->left!=NULL)
               {
                   q1.push(node1->left);

               }
               if (node1->right!=NULL)
               {
                   q1.push(node1->right);
                   
               }
               n1--;
                Node* node2=q2.front();
                q2.pop();
                if (node2->left!=NULL)
               {
                   q2.push(node2->left);

               }
               if (node2->right!=NULL)
               {
                   q2.push(node2->right);       
               }

                 curr_level1.push_back(node1->data);
                 curr_level2.push_back(node2->data);

            }

            sort(curr_level1.begin(),curr_level1.second());
            sort(curr_level2.begin(),curr_level2.second());
            if (curr_level1!=curr_level2)
            {
                return false;
            }
            
        }
    return true;


}
int main()
{
    Node* root1=create_Node(1);
    root1->left=create_Node(3);
    root1->right=create_Node(2);

     root1->left = create_Node(3);
    root1->right = create_Node(2);


     Node* root2 = create_Node(1);
    root2->left = create_Node(2);
    root2->right = create_Node(3);
    root2->left->left = create_Node(4);
    root2->left->right = create_Node(5);

    anagram_tree1_tree2(root1,root2) ? cout <<"True" :cout<<"False"<<secondl;
    return 0;

}
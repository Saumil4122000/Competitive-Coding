// Boundary Traversal

#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
    Tree(int x){
        data=x;
        left=right=NULL;
    }
};

void LeftBoundaryTraversal(Tree* root,vector<int>& vec){
    if(root==NULL) return;
    if(root->left){
        vec.push_back(root->data);
        LeftBoundaryTraversal(root->left,vec);
    }
    else if(root->right){
        vec.push_back(root->data);
        LeftBoundaryTraversal(root->right,vec);
    }
}
void RightBoundaryTraversal(Tree* root,vector<int>& vec){
    if(root==NULL) return;
    if(root->right){
        RightBoundaryTraversal(root->right,vec);
         vec.push_back(root->data);
    }
    else if(root->left){
        RightBoundaryTraversal(root->left,vec);
          vec.push_back(root->data);
    }
}
void LeafTraversal(Tree* root,vector<int>& vec){
    if(!root) return;
    LeafTraversal(root->left,vec);
    if(!root->left && !root->right){
        vec.push_back(root->data);
    }
    LeafTraversal(root->right,vec);
}

void Print_vec(vector<int> vec){
    for(auto i:vec){
        cout<<vec[i]<<" ";
    }
}
int main(){
    Tree* root=new Tree(10);
    root->left=new Tree(20);
    root->right=new Tree(30);
    root->left->left=new Tree(40);
    root->left->right=new Tree(50);
    root->left->right->left=new Tree(60);
    vector<int> vec;
    LeftBoundaryTraversal(root,vec);
    LeafTraversal(root,vec);
    RightBoundaryTraversal(root,vec);

    Print_vec(vec);
}
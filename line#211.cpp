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
void solve(Tree* root,int k,vector<int>& vec){
    if(!root) return;
    vec.push_back(root->data);
    solve(root->left,k,vec);
    solve(root->right,k,vec);
    int sum=0;
    for (int i = vec.size()-1; i >=0; i--)
    {
        sum+=vec[i];
        if(sum==k){
            for(int j=i;j<vec.size();j++){
                cout<<vec[j]<<" ";
            }
            cout<<endl;
        }
        
    }
    vec.pop_back();
}

void solveHelper(Tree* root,int k){
    vector<int> vec;
    solve(root,k,vec);
}
int main(){
    Tree *root = new Tree(1);
    root->left = new Tree(3);
    root->left->left = new Tree(2);
    root->left->right = new Tree(1);
    root->left->right->left = new Tree(1);
    root->right = new Tree(-1);
    root->right->left = new Tree(4);
    root->right->left->left = new Tree(1);
    root->right->left->right = new Tree(2);
    root->right->right = new Tree(5);
    root->right->right->right = new Tree(2);  
    int k=5;
    solveHelper(root,k); 
}
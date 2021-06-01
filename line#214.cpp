#include<bits/stdc++.h>
using namespace std;

class Tree{
	public:
	int data;
	Tree* left;
	Tree* right;

};
Tree* create_node(int data){
	Tree* temp=new Tree;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
Tree* insertion(Tree*  root,int key){
	if(root==NULL) return create_node(key);
	if(root->data>key) {
		root->left=insertion(root->left,key);
	}
	if(root->data<key){
		root->right=insertion(root->right,key);
	}
	return root;
}
void traversal(Tree* root){
	if(root==NULL) return;
	traversal(root->left);
	cout<<root->data<<" ";
	traversal(root->right);
}
Tree* searchKey(Tree* root,int x){
	if( root->data=x || root==NULL){
		return root;
	}
	else if(root->data>x){
		return searchKey(root->left,x);
	}
	else{
		return searchKey(root->right,x);
	}

}
int getMax(Tree* root){
	if(root==NULL) return -1;

	// Recursion
	// if(root->right==NULL) return root->data;
	// else return getMaz(root->right);


	// Iterative
	while (root->right)
	{
		root=root->right;
	}
	return root->data;
}
int getMin(Tree* root){
	if(root==NULL) return -1;

	// Recursion
	// if(root->left==NULL) return root->data;
	// else return getMin(root->left);


	// Iterative
	while (root->left)
	{
		root=root->left;
	}
	return root->data;
}
int main(){
	Tree* root=NULL;
	root=insertion(root,10);
	insertion(root,20);
	insertion(root,5);
	insertion(root,40);
	insertion(root,60);
	insertion(root,2);
	insertion(root,1);
	traversal(root);
	if(searchKey(root,20)){
		cout<<"PResent";
	}
	else{
		cout<<"Not Present";
	}
	int min=getMin(root);
	int max=getMax(root);
	cout<<min<<"\t"<<max;
}
#include <bits/stdc++.h>
using namespace std;
class Tnode{
    public:
    int val;
    Tnode* link;
};
Tnode* create_node(int val){
    Tnode* node=new Tnode();
    node->val=val;
    node->link=NULL;
    return node;
}
int main(){
   
}
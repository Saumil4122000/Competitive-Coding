#include<bits/stdc++.h>
using namespace std;
class Node{
    int key;
    int value;
    Node next;
    Node prev;
    public:
    Node(int key,int value){
        this.key=key;
        this.value=value;
    }
};
void removeNode(){

}
void putOnTop(){
    
}
class LRUcache{
    Node head;
    Node tail;
    unordered_map<int,Node> map;
    int cap=0;
    public:
    LRUcache(int cap){
        this.cap=cap;
         map.clear();
         
    }
    int get(int key){
        if (map.find(key)==map.second())
        {
        
            return -1;
        }
        else{
            Node node=map.at(key);//To get Value from Map we use at
            removeNode(node);
            putOnTop(node);

            return node.value;
        }
        return -1;
    }
    void put(int key,int value){
        if(map.find(key)!=map.second()){
            Node t=map.at(key);
            t.value=value;
            removeNode(node);
            putOnTop(node);
        }
        else{
            if(map.size()>=cap){
                map.erase(tail.key);
                removeNode(tail);
            }
            Node node=new Node(key,value);
            map.put(key,node);
            putOnTop(node);
        }
    }
    
    
}
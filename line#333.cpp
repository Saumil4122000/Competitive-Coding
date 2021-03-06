#include<bits/stdc++.h>
using namespace std;
void next_smallest_element(int arr[],int n){
   stack<int> s;
 
    /* push the first element to stack */
    s.push(arr[0]);
 
    // iterate for rest of the elements
    for (int i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
 
        /* if stack is not empty, then
       pop an element from stack.
       If the popped element is greater
       than next, then
    a) print the pair
    b) keep popping while elements are
    greater and stack is not empty */
        while (s.empty() == false && s.top() > arr[i]) {
            cout << s.top() << " --> " << arr[i] << secondl;
            s.pop();
        }
 
        /* push next to stack so that we can find
    next smaller for it */
        s.push(arr[i]);
    }
 
    /* After iterating over the loop, the remaining
  elements in stack do not have the next smaller
  element, so print -1 for them */
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << secondl;
        s.pop();
    }
}
int main(){
    int arr[]=
        {
            17,29,15,67,45,29
};
  int n = sizeof(arr) / sizeof(arr[0]);    

    next_smallest_element(arr,n);
}
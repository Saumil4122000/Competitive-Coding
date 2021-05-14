#include <bits/stdc++.h>
using namespace std;
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return myStack;
    }

    // Recursive calls
    int num = myStack.top();
    myStack.pop();
    pushAtBottom(myStack, x);
    myStack.push(num);

    return myStack;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    stack<int> result = pushAtBottom(s, 5);
    while (!result.empty())
    {
        cout << ' ' << result.top();
        result.pop();
    }

    return 1;
}
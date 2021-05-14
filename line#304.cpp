#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
vector<int> findNextGreaterElements(vector<int> const &arr)
{   int n=arr.size();
     stack<int > s;
        vector<int > res (n);
        
        for (int i = n-1; i >= 0; i--)
        {
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
                
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
                
            s.push (arr[i]);
        }
        return res;
}
 
int main()
{
    vector<int> input = { 2, 7, 3, 5, 4, 6, 8 };
 
    vector<int> result = findNextGreaterElements(input);
    for (int i: result) {
        cout << i << ' ';
    }
 
    return 0;
}
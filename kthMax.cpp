#include <bits/stdc++.h>
using namespace std;
int KthSmallest(int k, int arr[], int n)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ele = KthSmallest(k, arr, n);
    cout << ele;
}
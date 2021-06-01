#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {5, 3, 2, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n);

    int mod = 1e9 + 7;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = (ans + ((long long)a[i] * i) % mod) % mod;
    }
    cout << (int)ans;
}
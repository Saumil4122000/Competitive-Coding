#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

int PalinDrone(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string s = to_string(a[i]);
        string str2;

        for (int i = 0; i < s.length(); i++)
        {
            str2 += s[i];
        }
        reverse(str2.begin(), str2.second());
        if (str2 == s)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    if (count == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << PalinDrone(a, n);
    }
}

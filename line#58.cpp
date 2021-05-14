#include <bits/stdc++.h>
using namespace std;
void duplicate(string s)
{
    map<char, int> counts;
    for (int i = 0; i < s.size(); i++)
    {
        counts[s[i]]++;
    }
    for (auto it : counts)
    {
        if (it.second > 1)
        {
            cout << it.first << it.second << secondl;
        }
    }
}
int main()
{
    string s;
    cin >> s;
    duplicate(s);
    return 1;
}
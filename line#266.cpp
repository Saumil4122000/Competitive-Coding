#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int x[m], y[n];
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    sort(x, x + m, greater<int>());
    sort(y, y + n, greater<int>());
    int i = 0, j = 0;
    int ans = 0;
    int horizontal_count = 0, vertical_count = 0;
    while (i < m && j < n)
    {
        if (x[i] > y[j])
        {
            ans += vertical_count * x[i];
            horizontal_count++;
            i++;
        }
        else
        {
            ans += horizontal_count * y[j];
            vertical_count++;
            j++;
        }
    }

    while (i<n)
    {
        ans+=vertical_count*x[i];
        i++;
    }
    while (j<m)
    {
       ans+=horizontal_count*y[j];
       j++;
    }
    cout<<ans<<endl;
    
}

// we have given larger chocolate in square form 
// we have different cost to cut the chocolate in horizontal and for vertical  as well
//  task is to cut chocolate such that cost to cut the chocolate is min 

// go for video for better understanding

#include <bits/stdc++.h>
using namespace std;
int min_sub_arr_sum(int a[], int n, int k)
{
    int j = 0, count = 0, sum = 0, min_count = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        count++;
        while (sum > k)
        {
            min_count = min(count, min_count);
            sum -= a[j];
            if (sum > k)
            {
                count--;
                j++;
                min_count = min(min_count, count);
            }
            else
            {
                sum += a[j];
                break;
            }
        }
    }
    return min_count;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    cout << min_sub_arr_sum(a, n, k);
}
#include <bits/stdc++.h>
using namespace std;
void subset_poduct_max(int a[], int n)
{
    int no_of_zero=0, no_of_negative = 0;
    int product = 1;
    int max_neg = INT_MIN;

    // Find max product of subset of array
    // Case 1 all positive multiplied
    // All zero ignored
    // All negative
    // 1)Count noofnagative is even then product all negative
    // 2)if noofnegative is odd then we need not take largest negative number and product remaining negative
    // [-2,-1,-3] element then to make max product we choose on;y -2*-3 =6 and avoid -1
    // [-1,-2,-3,-4] we take all as final ans is positive
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            no_of_zero++;
            continue;
        }
        if (a[i] < 0)
        {
            no_of_negative++;
            if (max_neg < a[i])
            {
                max_neg = a[i];
            }
        }
        product *= a[i];
    }
    if (no_of_negative % 2 != 0)
    {
        if (no_of_negative == 1 && no_of_zero + no_of_negative==n)
        {
            product = 0;
        }
        product = product / max_neg;
    }

    cout << product;
}
int main()
{
    int a[] = {-1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    subset_poduct_max(a, n);
    return 1;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> no_of_candy_max_min(int candy[], int n, int k)
{
  
    int i=0;
    int j=n-1;
    sort(candy,candy+n);
    int min_price=0;
    while (i<=j)
    {
        min_price+=candy[i];
        i++;
        j-=k;
    }
    reverse(candy,candy+n);
    int max_price=0;
    i=0;
    j=n-1;
    while (i<=j)
    {
        max_price+=candy[i];
        i++;
        j-=k;
    }
    return {min_price,max_price};
}

/***
 * candy[] = {3, 2, 1, 4}
 * min=0
 * suppose k=2;
 * sort(candy) {1,2,3,4}
 * i=0 j=n-1
 * min+=1   then j=j-k so we get max price candy for free so j=1
 * i++
 * i=1 j=1
 * buy i=1 index candy 
 * min+=1+2=3
 * 
 * 
 * 
 * 
 * for max do reverse process
 * max=0
 * sort(candy) {4,3,2,1}
 * i=0 j=n-1
 * buy max price first and get min price ticket free
 * max+=4 get k chocolate free j=3-2=1;
 * i++ i=1 j=1
 * max=4+3=7
 * 
*/
int main()
{
    int n=4;
  
    // n= no of candy type
    int k;
    cin >> k;
    // k=no of candy type given free if buy one candy at a time
    int candy[] = {3, 2, 1, 4};
    // candy price of different type

    // Task is to find min and max amount to buy all candytype
    vector<int> vec = no_of_candy_max_min(candy, n, k);
    cout << "Min: " << vec[0] << " Max: " << vec[1];
}
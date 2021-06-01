#include <bits/stdc++.h>
using namespace std;
int min_platform(int arr[], int dept[], int n)
{
    sort(arr, arr + n);
    // Sorting the arrival array and dept array
    sort(dept, dept + n);
    int j = 0;
    // j points to dept array index
    int count=1;
    // Count is 1 because we always need one platform


    // k loop through the arr array

    for (int k = 1; k < n; k++)
    {
        // Check if arrival time of one train is less than the dept train then we need other platform(B)
        // After that just increment the i so new train will come and check its arrival time with station(a) departire time if yes then we can plca that train on Platform a
        if(arr[k]<=dept[j]){
            count++;            
        }


        else{
          j++;
        }
    }
    return count;
}

/*
 * arr[]={1,2,,6,8} dept[]={5,9,7,10}
 * sort both array arr[]={1,2,6,8} dept[]={5,7,9,10}
 * i=1 of arr  j=index 0 of dept
 * now arr[i](2) <dept[j](5) so we need more station so count++ so  count=2 
 * i++
 * i=3 j=0
 * arr[3](6)  > dept[j]{5} so we place this in plarform now j++,i++ 
 * j=1 i=4
 * arr[4](8)>  dept[j](7) don't need more station so j++,i++
 * and i=4 so comes out loop and return 2 station
  */
 
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int dept[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> dept[i];
    }
    int ans = min_platform(arr, dept, n);
    cout << ans;
    return 1;
}
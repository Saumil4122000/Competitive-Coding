#include <bits/stdc++.h>
using namespace std;
#define n 2
// No of station
#define m 5
// NO of train

int max_no_of_train(int a[][3]){
    // vector<pair<int,int>> vec[n+1];
    // // Declare no of vector equals to no of station
    // for (int i = 0; i < m; i++)
    // {
    //     // passing the a[i][2] as index a[i][2]=1 so store in vec 1
    //     vec[a[i][2]].push_back(make_pair(a[i][1],a[i][0]));
    // }
    // // sort trains for each platform as per
    // // dept. time
    // for (int i = 0; i <= n; i++)
    //    { sort(vec[i].begin(), vec[i].end());}
    
    // int count=0;
  
    // for (int i = 0; i <= n; i++)
    // {
    //     if(vec[i].size()==0){
    //         continue;
    //     }
    //     count++;
    //     int x=0;
    //     // First  train will always selected because it is having lesser time
    //     for (int j = 1; j < vec[i].size(); j++)
    //     {
    //         if(vec[i][j].second>=vec[i][x].first){
    //             count++;
    //             x=j;
    //         }
    //     }
        
    // }



    vector<pair<int,int>> vec[n+1];
    for (int i = 0; i < m; i++)
    {
        vec[a[i][2]].push_back(make_pair(a[i][1],a[i][0]));
    }
    
    for (int i = 0; i < n; i++)
    {
        sort(vec[i].begin(),vec[i].end());
    }
    int count=0;
    for (int i = 0; i <= n; i++)
    {
        if(vec[i].size()==0){
            continue;
        }
        count++;
        int x=0;
        for (int j = 1; j < vec[i].size(); j++)
        {
            if(vec[i][j].second>vec[i][x].first){
                count++;
                x=j;
            }
        }
        
    }
    
    
    return count;

}

int main()
{
   int arr[m][3] = { 1000, 1030, 1,
                      1010, 1020, 1,
                      1025, 1040, 1,
                      1130, 1145, 2,
                      1130, 1140, 2 };
  
    int size=max_no_of_train(arr);
    cout<<size;

}
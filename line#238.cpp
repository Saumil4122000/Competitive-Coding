#include <bits/stdc++.h>
using namespace std;
 bool comp(pair<int, int> a,pair<int, int> b ){
     if(a.second==b.first) return a.first<b.first;
     return a.second<b.second;
 }
 
 
  void no_of_jobs(int start[], int end[], int n)
{
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = {start[i], end[i]};
    }
    sort(vec.begin(), vec.end(), comp);
    int i = 0;
    int j = 1;
    int count = 1;
    //  I have already taken count is 1 because last timing will always taken
    while (j < n)
    {
        if(vec[i].second<vec[j].first){
            count++;
            i=j;
            j++;
        }
        else{
            j++;
        }
    }

    cout<<count;
}


int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    no_of_jobs(start, end, 6);
 }
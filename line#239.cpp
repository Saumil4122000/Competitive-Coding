#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
    int prof;
    int id;
    int dead;
};

bool Comparator(Job a,Job b){
    return a.prof>b.prof;
}

vector<int> JobScheduling(Job arr[],int n){
    sort(arr,arr+n,Comparator);
    // Sort Array according to prof in decreasing order
    int day=0;
    // No of jobs
    int profite=0;
    bool ans[n]={0};
    for (int i = 0; i < n; i++)
    {
        // Loop through all array position
        for (int  j = min(n,arr[i].dead-1);j>=0; j--)
        // find in deadline array position we find highest prof job and try to schedule it just before deadlinetime
        // If it is not present then search before position then current
        {
            if(ans[j]==false){
                day+=1;
                profite+=arr[i].prof;
                ans[j]=true;
                break;
                // Once we done with
            }
        }
        
    }
    return {day,profite};
    
}

int main(){
    int n;
    cin>>n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        arr[i].id=x;
        arr[i].dead=y;
        arr[i].prof=z;
    }

    vector<int> vec= JobScheduling(arr,n);
    cout<<vec[0]<<' '<<vec[1];
    
}


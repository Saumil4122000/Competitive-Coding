#include<bits/stdc++.h>
using namespace std;
bool Comparator(vector<int> a,vector<int> b){
// a[1]==arival time
// a[2]==burst time
// a[0]==id   
    if(a[1]==b[1]){
        // arrival is same
        if(a[2]==b[2]){
            // burst time same then sort according to processid
            return a[0]<b[0];
        }
        else{
            // arrival is same but  burst time not same then sort according to bursttime
            return a[2]<b[2];
        }
    }
    // arrival is not same then sort it with arrival time
    return a[1]<b[1];
}
int main(){

    int n;
    cin>>n;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin>>x;
            vec[i].push_back(x);
        }
        
    }
    
    sort(vec.begin(),vec.end(),Comparator);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({vec[0][2],vec[0][1],vec[0][0]});
    int i=1;
    vector<int> ans;
    int current_time=0;
    while (!pq.empty())
    {
       int id=pq.top()[2];
        int burstTime=pq.top()[0];
        pq.pop();
        ans.push_back(id);
        current_time+=burstTime;
        while (true)
        {
            if(i<n && vec[i][1]<current_time){
                pq.push({vec[i][2],vec[i][1],vec[i][0]});
                i++;
            }
            else{
                break;
            }
        }
        
    }
    for (int i = 0; i < ans.size(); i++)
    {
       cout<<ans[i]<<"\t";
    }
    cout<<"\n"<<current_time;
    
    


}
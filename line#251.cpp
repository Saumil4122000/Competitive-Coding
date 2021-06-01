#include<bits/stdc++.h>
using namespace std;

class Meeting{
    public:
    int start;
    int end;
    int position;
};

// Comparator function which can compare
// the second element of structure used to
// sort pairs in increasing order of second value.
bool comparator(Meeting m1,Meeting m2){
    return (m1.end<m2.end);
}

void max_Meeting(int start[],int end[],int n){

    Meeting meet[n];

    for (int i = 0; i < n; i++)
    { // Starting time of meeting i.
        meet[i].start=start[i];
         // Finishing time of meeting i
        meet[i].end=end[i];
        
        // Original position/index of meeting
        meet[i].position=i+1;
    }
     // Sorting of meeting according to their finish time.
    sort(meet,meet+n,comparator);
    // Vector for storing selected meeting.
    vector<int> vec;
    vec.push_back(meet[0].position);
    // Initially select first meeting.
    int timeline=meet[0].end;
     
    // Check for all meeting whether it
    // can be selected or not.
    for (int i = 1; i < n; i++)
    {
        if(meet[i].start>=timeline){
             // Push selected meeting to vector
            vec.push_back(meet[i].position);
            // Update time limit.
            timeline=meet[i].end;
        }
    }
    // Print final selected meetings.
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }  
}

int main(){
     // Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
     
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    max_Meeting(s, f, n);
    return 1;
}
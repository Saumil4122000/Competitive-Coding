#include <bits/stdc++.h>
using namespace std;
void no_of_page_fault(int pages[], int N, int C)
{
    vector<int> v;
    // Holding the frames
    int faults = 0;
    vector<int>::iterator it;
    for (int i = 0; i < N; i++)
    {
        it = find(v.begin(), v.end(), pages[i]);
        // Search in frame to check if it exist or not
        if (it == v.end())
        // If frame not exist
        {
            if (v.size() == C)
            // And size of vec is full
                v.erase(v.begin());
                // Remove from front end of frame
            v.push_back(pages[i]);
            // 
            faults++;
        }
        else
        {
            v.erase(it);
            v.push_back(pages[i]);
        }
    }
        cout << faults;
}
    int main()
    {
        int N, C;
        cin >> N;
        cin >> C;
        int pages[N];
        for (int i = 0; i < N; i++)
        {
            cin >> pages[i];
        }
        no_of_page_fault(pages, N, C);
    }
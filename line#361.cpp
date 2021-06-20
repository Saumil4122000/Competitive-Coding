#include <bits/stdc++.h>
using namespace std;

// void dfs(string s,int i,int j,vector<vector<int>> &visit,int  m[][4],int n){
//     if(i<0 or j<0 or i>=n or j>=n) return;
//     if(i==n-1 and j==n-1)
//     {
//         v.push_back(s);
//         return;
//     }

//     visit[i][j]=1;
//     dfs(s+'U',i-1,j,visit,m,n);
//     dfs(s+'D',i+1,j,visit,m,n);
//     dfs(s+'L',i,j-1,visit,m,n);
//     dfs(s+'R',i,j+1,visit,m,n);
//     visit[i][j]=0;

// }

void find(vector<vector<int>> &m, string s, int n, int i, int j, vector<string> &ans)
{
    if (i == n - 1 && j == n - 1)
    {
        // if we reach the final position then put the string into ans vector
        ans.push_back(s);
        return;
    }
    if (i >= 0 && j >= 0 && i < n && j < n && m[i][j])
    {
        // if current array element is 1 then we go up down left right
        m[i][j] = 0;
        // we place 0 in current position so that we can't get current position again and again
        find(m, s + "D", n, i + 1, j, ans);
        find(m, s + "L", n, i, j - 1, ans);
        find(m, s + "R", n, i, j + 1, ans);
        find(m, s + "U", n, i - 1, j, ans);

        // we move all directions
        m[i][j] = 1;
        // at last we place 1 so that after it we get other paths as well
    }
    return;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return ans;
    // If initial and final position is 0 then we can't move further

    string s;
    find(m, s, n, 0, 0, ans);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n,vector<int>(n,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }


    vector<string> ans = findPath(m, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}




/***
 * In this our task is to find different path by which we can go from [0,0] to [n-1,n-1]
 * but some position in array is 0 so we can't cross it

 * ***/
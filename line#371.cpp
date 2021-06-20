#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, int N, int M, int vis[][501], vector<vector<int>> grid)
{
    if (i < 0 || i >= N || j < 0 || j >= M)
        return;
    if (grid[i][j] == 0)
        return;
    if (!vis[i][j])
    {
        vis[i][j] = 1;
        dfs(i - 1, j - 1, N, M, vis, grid);
        dfs(i - 1, j, N, M, vis, grid);
        dfs(i - 1, j + 1, N, M, vis, grid);
        dfs(i + 1, j - 1, N, M, vis, grid);
        dfs(i + 1, j, N, M, vis, grid);
        dfs(i + 1, j + 1, N, M, vis, grid);
        dfs(i, j - 1, N, M, vis, grid);
        dfs(i, j + 1, N, M, vis, grid);
    }
}
int numOfIsland(vector<vector<int>> &grid)
{
    int c = 0;
    int n = grid.size();
    int m = grid[0].size();
    int vis[501][501];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                dfs(i, j, n, m, vis, grid);
                c++;
            }
        }
    }
    return c;
}
int main()
{
    int n, m;
    n = 2;
    m = 9;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    grid = {{1, 1, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 1, 0, 0, 1, 0, 0, 1}};

    int c = numOfIsland(grid);
    cout << c;
}
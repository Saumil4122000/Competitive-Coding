#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &image, int newColor, int oldColor, int x, int y)
{

// Boundary Condition
    if (i < 0 or i >= x or j < 0 or j >= y)
    {
        return;
    }

// if it is already visited or we have already colored it so return
    if (vis[i][j] or image[i][j] != oldColor)
        return;

    vis[i][j] = 1;
    image[i][j] = newColor;
    dfs(i + 1, j, vis, image, newColor, oldColor, x, y);
    dfs(i - 1, j, vis, image, newColor, oldColor, x, y);
    dfs(i, j + 1, vis, image, newColor, oldColor, x, y);
    dfs(i, j - 1, vis, image, newColor, oldColor, x, y);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int x = image.size();
    int y = image[0].size();
    vector<vector<int>> vis(x, vector<int>(y, 0));
    int oldColor = image[sr][sc];
    dfs(sr, sc, vis, image, newColor, oldColor, x, y);
    return image;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> image(n,vector<int>(n,0));
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j< image[i].size(); j++)
        {
            cin>>image[i][j];
        }
        
    }
    
    vector<vector<int>> ans=floodFill(image,1,1,2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j< ans[i].size(); j++)
        {
            cout<<ans[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

/**
 *  In this problem we have given 2d vector and in 2d vector we have given values
 * 
 *  1 1 1           2 2 2 
 *  1 1 0       =>  2 2 0 =>
 *  1 0 1           2 0 1
 * 
 * and given position  sr=1 sc=1 and given newColor=2
 * 
 * Our task is color all the cells which is side by side adjancent to vec[1][1]
 * 
 * which is vec[1][0] vec[1][2] vec[0][1] vec[2][1]
 * 
 * we need to color all this above elements by newColor
 * 
 * and in the same way we need that all cells that are adjancent to vec[1][0] vec[1][2] vec[0][1] vec[2][1] are required to be color
 *  
 * 
 * 
 * ***/
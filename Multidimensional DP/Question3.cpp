#include<bits/stdc++.h>
using namespace std;

int uniquePath(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    if(grid[0][0]==1 || grid[n-1][m-1]==1){
        return 0;
    }
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if(grid[0][i]==0 && dp[0][i-1]==1){
            dp[0][i] = 1;
        }else{
            break;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if(grid[i][0]==0 && dp[i-1][0]==1){
            dp[i][0] = 1;
        }else{
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(grid[i][j]==0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<"No of possible paths: "<<uniquePath(grid);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int maxSquare(vector<vector<char>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSide = 0;
    vector<vector<int>> dp(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i] - '0';
        maxSide = max(maxSide,dp[0][i]); 
    }
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = matrix[i][0] - '0';
        maxSide = max(maxSide,dp[i][0]); 
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if(matrix[i][j]=='1'){
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
                maxSide = max(maxSide,dp[i][j]);  
            }  
        }
    }
    return (maxSide*maxSide);
}

int main()
{
    vector<vector<char>> matrix = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'}
    };
    cout<<"the area of largest square with only 1's is: "<<maxSquare(matrix);
    return 0;
}
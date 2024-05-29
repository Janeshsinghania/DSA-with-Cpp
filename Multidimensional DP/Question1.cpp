#include<bits/stdc++.h>
using namespace std;
int minTotal(vector<vector<int>> triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[n-1] = triangle[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
        }
        
    }
    return dp[0][0];
}

int main()
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<"Min path sum: "<<minTotal(triangle);
    return 0;
}
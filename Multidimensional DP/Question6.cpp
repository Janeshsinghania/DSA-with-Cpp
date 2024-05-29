#include<bits/stdc++.h>
using namespace std;

int solve(string &a, string &b, int i, int j, vector<vector<int>>& dp){
    if(i==a.length()){
        return b.length() - j;
    }
    if(j==b.length()){
        return a.length() - i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans= 0;
    if(a[i]==b[j]){
        return solve(a,b,i+1,j+1,dp);
    }
    else{
        //insert
        int insertAns = 1 + solve(a,b,i,j+1,dp);
        //delete
        int deleteAns = 1 + solve(a,b,i+1,j,dp);
        //replace
        int replaceAns = 1 + solve(a,b,i+1,j+1,dp);
        ans = min(insertAns,min(deleteAns,replaceAns));
    }
    return dp[i][j] = ans;
}

int minDistance(string word1, string word2){
    vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
    return solve(word1,word2,0,0,dp);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    cout<<"Min no of operations required: "<<minDistance(word1,word2);
    return 0;
}
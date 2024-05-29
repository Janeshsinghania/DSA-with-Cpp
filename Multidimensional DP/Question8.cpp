#include<bits/stdc++.h>
using namespace std;

int solve(int index, int operations, int k, vector<int>& prices, vector<vector<int>>& dp){
    if(index==prices.size()){
        return 0;
    }
    if(operations==2*k){
        return 0;
    }
    if(dp[index][operations]!=-1){
        return dp[index][operations];
    }
    int profit = 0;
    if(operations%2==0){
        int buykaro = -prices[index] + solve(index+1,operations+1,k,prices,dp);
        int skipkaro = 0 + solve(index+1,operations,k,prices,dp);
        profit = max(buykaro,skipkaro);
    }
    else{
        int sellkaro = prices[index] + solve(index+1,operations+1,k,prices,dp);
        int skipkaro = 0 + solve(index+1,operations,k,prices,dp);
        profit = max(sellkaro,skipkaro);
    }
    return dp[index][operations] = profit;
}

int maxProfit(vector<int> prices,int k){
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
    return solve(0,0,k,prices,dp);
}

int main()
{
    vector<int> prices = {3,2,6,5,0,3};
    int k;
    cin>>k;
    cout<<"Maximum profit: "<<maxProfit(prices,k);
    return 0;
}
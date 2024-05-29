#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int n = s.size();
    if(n==0) return "";
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    int maxLen = 1;
    int startIdx = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    for (int i = 0; i < n-1; i++)
    {
        if(s[i]==s[i+1]){
            dp[i][i+1] = true;
            maxLen = 2;
            startIdx = i;
        }
    }
    for (int i = 3; i <=n ; i++)
    {
        for (int j = 0; j <= n-i; j++)
        {
            int x = j+i-1;
            if(s[j]==s[x] && dp[j+1][x-1]){
                dp[i][j] = true;
                if(i>maxLen){
                    maxLen = i;
                    startIdx = j;
                }
            }
        }
        
    }
    return s.substr(startIdx,maxLen);
}

int main()
{
    string s = "babad";
    cout<<"Longest palindromic subsequence: "<<longestPalindrome(s);
    return 0;
}
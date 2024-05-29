#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> word){
    unordered_set<string> dict (word.begin(),word.end());
    int n = s.length();
    vector<bool> dp(n+1,false);
    dp[0] = true; //empty string is always true
    for (int i = 1; i <=n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(dp[j] && dict.find(s.substr(j,i-j)) != dict.end()){
                dp[i] = true;
                break;
            }
        }
        
    }
    return dp[n];
}

int main()
{
    string s = "leetcode";
    vector<string> word = {"leet","codes"};
    cout << (wordBreak(s, word) ? "String can be segmented." : "String cannot be segmented.") << endl;
    return 0;
}
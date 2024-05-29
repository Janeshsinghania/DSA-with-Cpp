#include<bits/stdc++.h>
using namespace std;

void longestSubstring(string s){
    vector<int> pos(128, -1);
    int n = s.size();
    int start = -1;
    int maxLen = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(pos[s[i]] > start){
            start = pos[s[i]];
        }
        pos[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }
    cout<<maxLen;
}

int main()
{
    string s = "abcdabcbb";
    longestSubstring(s);
    return 0;
}
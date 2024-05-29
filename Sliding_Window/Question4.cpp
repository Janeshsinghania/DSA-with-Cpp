#include<bits/stdc++.h>
using namespace std;

void minWindow(string s, string t){
    int m = s.size();
    int n = t.size();
    if(s.size() < t.size()){
        cout<<"-1";
    }
    vector<int> mp1(256,0);
    vector<int> mp2(256,0);
    int count = 0;
    int startIndex = -1 , len = INT_MAX;
    for (auto ch: t)
    {
        mp1[ch]++;
    }
    int i = 0 , j = 0;
    while (j<m)
    {
        mp2[s[j]]++;
        if(mp2[s[j]] <= mp1[s[j]]){
            count++;
        }
        if(count==n){
            while(mp2[s[i]]>mp1[s[i]] || mp1[s[i]]==0){
                if(mp2[s[i]]>mp1[s[i]]){
                    mp2[s[i]]--;
                }
                i++;
            }
            if(len > j-i+1){
                len = j-i+1;
                startIndex = i;
            }
        }
        j++;
    }
    if(startIndex==-1){
        cout<<"-1";
    }
    cout<<s.substr(startIndex,len);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    minWindow(s,t);
    return 0;
}
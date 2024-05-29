#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagram(vector<string> strs){
    vector<vector<string>> res;
    int n = strs.size();
    unordered_map<string,vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        string word = strs[i];
        sort(word.begin(),word.end());
        mp[word].push_back(strs[i]);
    }
    for(auto x:mp){
        res.push_back(x.second);
    }
    return res;
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagram(strs);
    for(auto ch: ans){
        for(auto x: ch){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
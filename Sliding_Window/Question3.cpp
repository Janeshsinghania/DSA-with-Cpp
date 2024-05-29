#include<bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string> words){
    int n = words.size();    //2
    int m = words[0].size();   //3
    vector<int> ans;
    if(s.size()<m*n){
        return ans;
    }
    for (int i = 0; i <= s.size() - (m*n); i++)
    {
        unordered_map<string,int> mp;
        for (int j = 0; j < n; j++)
        {
            mp[words[j]]++;
        }
        int t;
        for (t = 0; t < n; t++)
        {
            string str = s.substr(i+t*m,m);
            if(mp.count(str)==0){
                break;
            }
            else{
                if(mp[str]!=0){
                    mp[str]--;
                }else{
                    break;
                }
            }
        }
        if(t==n){
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> ans = findSubstring(s,words);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}
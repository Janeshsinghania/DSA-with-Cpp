#include<bits/stdc++.h>
using namespace std;

bool anagram(string s, string t){
    if(s.size()!=t.size()){
        return false;
    }
    int n = s.size();
    unordered_map<char,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if(mp.find(t[i])==mp.end() || mp[t[i]]==0){
            return false;
        }
        else{
            mp[t[i]]--;
        }
    }
    return true;
    
}

int main()
{
    string s = "silent";
    string t = "listen";
    bool result = anagram(s,t);
    if(result){
        cout<<"Valid anagram";
    }
    else{
        cout<<"Invalid anagram";
    }
    return 0;
}
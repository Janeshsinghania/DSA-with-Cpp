#include<bits/stdc++.h>
using namespace std;

bool isomorphic(string s, string t){
    if(s.size()!=t.size()){
        return false;
    }
    int n = s.size();
    unordered_map<char,char> mp1,mp2;
    for (int i = 0; i < n; i++)
    {
        if(mp1[s[i]] && mp1[s[i]]!=t[i]){return false;}
        if(mp2[t[i]] && mp2[t[i]]!=s[i]){return false;}
        mp1[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }
    return true;
}

int main()
{
    string s = "egg";
    string t = "adb";
    bool result = isomorphic(s,t);
    if(result){
        cout<<"valid isomorphic string";
    }
    else{
        cout<<"invalid isomorphic string";
    }
}
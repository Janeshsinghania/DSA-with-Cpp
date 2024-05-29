#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string r, string m){
    unordered_map<char,int> mp;
    for(auto ch: m){
        mp[ch]++;
    }
    for(auto c: r){
        if(mp[c]){
            mp[c]--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main()
{
    string ransomNote = "janesh ";
    string magazine = "sinjanghaniaesh";
    bool result = canConstruct(ransomNote,magazine);
    if(result){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
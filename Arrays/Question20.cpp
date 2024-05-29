#include<bits/stdc++.h>
using namespace std;

void longestCommonPrefix(vector<string> name){
    sort(name.begin() , name.end());
    string s = name[0];
    string s1 = name[name.size() - 1];
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]==s1[i]){
            ans += s[i];
        }
        else break;
    }
    cout<<ans;
}

int main()
{
    vector<string> name = {"Janesh" , "Jay" , "Jai"};
    longestCommonPrefix(name);
}
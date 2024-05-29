#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t){
    int n = s.size();
    int m = t.size();
    int i = 0, j=0;
    while (i<n && j<m)
    {
        if(s[i]==t[j]){
            i++;
        }
        j++;
    }
    if(i==n){
        return true;
    }else{
        return false;
    }
    
}

int main()
{
    string s = "acb";
    string t = "ahbdgc";
    if(isSubsequence(s,t)){
        cout<<"Valid subsequence";
    }else{
        cout<<"Not a valid subsequence";
    }
    return 0;
}
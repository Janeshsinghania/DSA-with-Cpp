#include<bits/stdc++.h>
using namespace std;

void romantoInt(string S){
    unordered_map<char,int> m;
    int ans = 0;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    for (int i = 0; i < S.size(); i++)
    {
        if(m[S[i]] < m[S[i+1]]){
            ans -= m[S[i]];
        }
        else{
            ans += m[S[i]];
        }
    }
    cout<<ans;
    
}

int main()
{
    string S = "III";
    romantoInt(S);
}
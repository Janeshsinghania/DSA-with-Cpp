#include<bits/stdc++.h>
using namespace std;

void reverseWords(string s){
    int n = s.size();
    string ans = "";
    vector<string> a;
    for (int i = 0; i < n; i++)
    {
        if(s[i]==' '){
            if(ans.size()!=0){
                a.push_back(ans);
            }
            ans = "";
        }
        else{
             ans+=s[i];
        }
    }
    if(ans.size()>0 && ans[0]!= ' '){
        a.push_back(ans);
    }
    string F_ans = "";
    int m = a.size();
    for (int i = m-1; i >=0; i--)
    {
        F_ans += a[i];
        F_ans += ' ';
    }
    cout<<F_ans;
}

int main()
{
    string s = "a good example";
    reverseWords(s);
}


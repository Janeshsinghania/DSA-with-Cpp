#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path){
    int n = path.size();
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        string s = "";
        if(path[i]=='/'){
            continue;
        }
        while (i<n && path[i]!='/')
        {
            s += path[i++];
        }
        if(s==".."){
            if(!st.empty()){
                st.pop();
            }
        }
        else if(s=="."){
            continue;
        }
        else{
            st.push(s);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans = "/" + st.top() + ans;;
        st.pop();
    }
    return ans;
}

int main()
{
    string path = "/home//foo/";
    string res= simplifyPath(path);
    cout<<res;
}
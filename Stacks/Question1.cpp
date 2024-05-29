#include<bits/stdc++.h>
using namespace std;

bool checkParen(string paren){
    int n = paren.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if(paren[i]=='{' || paren[i]=='(' || paren[i]=='['){
            st.push(paren[i]);
        }
        else{
            if(!st.empty()){
                if((paren[i]=='}' && st.top()=='{') || (paren[i]==')' && st.top()=='(')||
                (paren[i]==']' && st.top()=='[')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
    }
    return st.empty();
}

int main()
{
    string paren = "{}()[]";
    bool result = checkParen(paren);
    if(result){
        cout<<"Valid parenthesis";
    }else{
        cout<<"Invalid parenthesis";
    }
}
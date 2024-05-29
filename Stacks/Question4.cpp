#include<bits/stdc++.h>
using namespace std;

int reverseNotation(vector<string> tokens){
    stack<int> st;
    long op1,op2;
    unordered_set<string> operand = {"+" , "-" , "*" , "/"};
    for(auto i : tokens){
        if(operand.find(i)==operand.end()){
            st.push(stoi(i));
        }
        else{
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();
            if(i=="+"){
                st.push(op1+op2);
            }
            else if(i=="-"){
                st.push(op2-op1);
            }
            else if(i=="*"){
                st.push(op1*op2);
            }
            else if(i=="/"){
                st.push(op2/op1);
            }
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans = reverseNotation(tokens);
    cout<<ans;
    return 0;
}
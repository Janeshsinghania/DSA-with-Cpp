#include<bits/stdc++.h>
using namespace std;

class Mainstack{
    public:
    stack<int> st1;
    stack<int> st2;
    Mainstack(){
        
    }
    void push(int val){
        st1.push(val);
        if(st2.empty() || val<=st2.top()){
            st2.push(val);
        }
    }
    void pop(){
        if(!st1.empty() && !st2.empty() && st1.top()==st2.top()){
            st2.pop();
        }
        st1.pop();
    }
    int top(){
        if(!st1.empty()){
            return st1.top();
        }else{
            return -1;
        }
    }
    int min(){
        if(!st2.empty()){
            return st2.top();
        }else{
            return -1;
        }
    }
};

int main()
{
    Mainstack st;
    st.push(3);
    st.push(0);
    st.push(1);
    st.push(-1);
    cout<<"Top element of stack"<<st.top()<<endl;
    cout<<"minimum value of stack"<<st.min()<<endl;
    st.pop();
    cout<<"minimum value of stack after pop"<<st.min()<<endl;
    cout<<st.top();

}
#include<bits/stdc++.h>
using namespace std;

bool happy(int num){
    set<int> st;
    while(num!=1 && st.find(num)==st.end()){
        st.insert(num);
        int sum = 0;
        while(num>0){
            int n = num%10;
            sum += n*n;
            num = num/10;
        }
        num = sum;
    }
    return num==1;
}

int main()
{
    int num = 20;
    bool result = happy(num);
    if(result){
        cout<<"happy number";
    }
    else{
        cout<<"not a happy number";
    }
}
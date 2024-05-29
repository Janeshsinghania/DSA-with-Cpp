#include<bits/stdc++.h>
using namespace std;

void zigZag(string s , int numberofRows){
    vector<string> A(numberofRows);
    if(numberofRows == 1){
        cout<<s;
    }
    int i = 0;
    bool flag = false;
    for (auto ch: s)
    {
        A[i] += ch;
        if(i==0 || i==numberofRows -1){
            flag = !flag;
        }
        if(flag){
            i = i+1;
        }
        else{
            i = i-1;
        }
    }
    string res = "";
    for (auto x: A)
    {
        res += x;
    }
    
    cout<<res;
}

int main()
{
    string s = "PAYPALISHIRING";
    zigZag(s , 4);
    return 0;
}
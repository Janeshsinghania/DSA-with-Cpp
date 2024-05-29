#include<bits/stdc++.h>
using namespace std;

string addBinary(string A, string B){
    string result;
    int n = max(A.size(),B.size());
    int carry = 0;
    A = string(n-A.size(),0) + A;
    B = string(n-B.size(),0) + B;
    for (int i = n-1; i>=0; i--)
    {
        int sum = (A[i]-'0') + (B[i] - '0') + carry;
        result.push_back(sum%2 + '0');
        carry = sum/2;
    }
    if(carry>0){
        result.push_back(carry + '0');
    }
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    string A = "1010";
    string B = "1011";

    string sum = addBinary(A,B);
    cout<<"Sum: "<<sum;
    return 0;
}
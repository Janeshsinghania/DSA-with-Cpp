#include<bits/stdc++.h>
using namespace std;

double calPower(double x, int n){
    if(n==0){
        return 1.0;
    }
    double halfPower = calPower(x,n/2);
    if(n %2 ==0){
        return halfPower*halfPower;
    }else{
        return (n>0)? x*halfPower*halfPower : (1/x)*halfPower*halfPower;
    }
}

int main()
{
    double x = 2.0;
    int n = 5.0;
    double result = calPower(x,n);
    cout<<result;
    return 0;
}
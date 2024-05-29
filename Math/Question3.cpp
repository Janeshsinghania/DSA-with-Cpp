#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int n){
    int count = 0;
    while(n>=5){
        n/=5;
        count+=n;
    }
    return count;
}

int main()
{
    int n = 150;
    int result = trailingZeroes(n);
    cout<<"tariling zeroes of"<<n<<"factorial are: "<<result;
    return 0;
}
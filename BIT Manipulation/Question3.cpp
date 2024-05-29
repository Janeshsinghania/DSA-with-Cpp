#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n){
    int count = 0;
    while (n!=0)
    {
        count += n & 1;
        n>>=1;
    }
    return count;
}

int main()
{
    uint32_t n = 31;
    int res = hammingWeight(n);
    cout<<"hamming weight of "<<n<<"is: "<<res<<endl;
    return 0;
}
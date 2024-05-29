#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x){
    if(x==0 || x==1){
        return x;
    }
    int start = 1;
    int end = x/2;
    int ans = 0;
    while(start<=end){
        int mid = (start+end)/2;
        if(mid<=x/mid){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

int main()
{
    int x = 14;
    int result = mySqrt(x);
    cout<<"square root of given no is: "<<result;
    return 0;
}
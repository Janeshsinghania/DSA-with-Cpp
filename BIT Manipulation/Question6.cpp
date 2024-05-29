#include<bits/stdc++.h>
using namespace std;

int range(int left, int right){
    int result = 0;
    int count = 0;
    while(left<right){
        left>>=1;
        right>>=1;
        count++;
    }
    return left<<count;
}

int main()
{
    int left = 5;
    int right = 7;
    int result = range(left,right);
    cout<<"Range between"<<left<<"and"<<right<<"is: "<<result;
    return 0;
}
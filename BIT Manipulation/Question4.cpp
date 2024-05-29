#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> nums){
    int result = 0;
    for(auto x: nums){
        result ^= x;
    }
    return result;
}

int main()
{
    vector<int> nums = {4,2,4,2,6,7,6};
    int result = singleNumber(nums);
    cout<<"the single number is: "<<result;
    return 0;
}
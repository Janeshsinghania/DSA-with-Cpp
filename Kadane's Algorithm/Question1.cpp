#include<bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> nums){
    int n = nums.size();
    int curr = nums[0];
    int maxSum = 0;
    for (int i = 1; i < n; i++)
    {
        curr = max(nums[i],curr + nums[i]);
        maxSum = max(maxSum,curr);
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubarray(nums);
    cout<<"Max subarray sum: "<<result;
    return 0;
}
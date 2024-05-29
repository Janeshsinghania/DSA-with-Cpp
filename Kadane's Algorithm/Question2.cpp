#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int> nums){
    int n = nums.size();
    int currMax = nums[0];
    int maxSum = INT_MIN;
    int currMin = 0;
    int totalSum = 0;
    int minSum = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        currMax = max(nums[i],currMax + nums[i]);
        maxSum = max(maxSum,currMax);
    }
    
    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];
        currMin = min(nums[i],currMin + nums[i]);
        minSum = min(minSum,currMin); 
    }
    if(totalSum==minSum){
        return maxSum;
    }
    return max(maxSum,totalSum-minSum);
}

int main()
{
    vector<int> nums = {5,-3,5};
    int result = maxSubarraySumCircular(nums);
    cout<<"Max circular subarray sum: "<<result;
    return 0;
}
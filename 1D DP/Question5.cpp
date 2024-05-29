#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> nums){
    int n = nums.size();
    if(n==0 || n==1){
        return n;
    }
    vector<int> dp(n+1,1);
    int maxLength = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i],dp[j]+1);
                maxLength = max(maxLength,dp[i]);
            }
        }
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<"Length of the increasing subsequence: "<<LIS(nums);
    return 0;
}
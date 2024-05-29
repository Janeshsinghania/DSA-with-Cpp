#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int> nums){
    int n = nums.size();
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        int start = nums[i];
        while (i+1<n && nums[i+1]==nums[i]+1)
        {
            i++;
        }
        int end = nums[i];
        if(start==end){
            res.push_back(to_string(start));
        }
        if(start!=end){
            res.push_back(to_string(start) + "->" + to_string(end));
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {0,1,2,4,5,6,7};
    vector<string> result = summaryRanges(nums);
    for(auto x: result){
        cout<<x<<",";
    }
}
#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> nums, int target){
    vector<int> result = {-1,-1};
    int left = 0;
    int right = nums.size()-1;
    //leftmost occurence of the target
    while(left<=right){
        int mid = (left+right)/2;
        if(target==nums[mid]){
            result[0] = mid;
            right = mid-1;
        }else if(target<nums[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    //rightmost occurence of the target
    left = 0;
    right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(target == nums[mid]){
            result[1] = mid;
            left = mid+1;
        }else if(target<nums[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> result = searchRange(nums,target);
    for(auto x: result){
        cout<<x<<" ";
    }
    return 0;
}
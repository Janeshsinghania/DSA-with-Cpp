#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> nums,int target){
    int left = 0;
    int right = nums.size()-1;
    int mid;
    if(target>nums[right]){
        return right+1;
    }
    while(left<right){
        mid = (left+right)/2;
        if(target==nums[mid]){
            return mid;
        }    
        if(target<nums[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return left;
}

int main()
{
    vector<int> nums = {1,3,5,8};
    int target = 7;
    int result = searchInsert(nums,target);
    cout<<"index where it is found or inserted: "<<result;
    return 0;
}
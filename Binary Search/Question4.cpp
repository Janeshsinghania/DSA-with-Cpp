#include<bits/stdc++.h>
using namespace std;

int searchIndex(vector<int> nums, int target){
    int left = 0;
    int right = nums.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(target==nums[mid]){
            return mid;
        }
        if(nums[left]<=nums[mid]){
            if(nums[left]<=target && target< nums[mid]){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }else{
            if(nums[mid]<target && target<= nums[right]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 1;
    int result = searchIndex(nums,target);
    cout<<result;
    return 0;
}
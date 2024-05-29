#include<bits/stdc++.h>
using namespace std;

int maxElementIndex(vector<int> nums){
    int left = 0;
    int right = nums.size()-1;
    while(left<right){
        int mid = (left+right)/2;
        if(nums[mid]>nums[mid+1]){   //if the elemnt is present at left index
           right = mid;
        }else{
            left = mid+1;
        }
    }
    return left;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int result = maxElementIndex(nums);
    cout<<result;
    return 0;
}
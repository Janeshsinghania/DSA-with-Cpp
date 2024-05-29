#include<bits/stdc++.h>
using namespace std;

int findKthlargest(vector<int> nums, int k){
    int n = nums.size();
    priority_queue<int,vector<int>, greater<int>> minHeap;
    for(int n: nums){
        minHeap.push(n);
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main()
{
    vector<int> nums = {1,2,3,5,8,9};
    int k =2;
    int result = findKthlargest(nums,k);
    cout<<"largest Kth element: "<<result;
    return 0;
}
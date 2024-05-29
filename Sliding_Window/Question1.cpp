#include<bits/stdc++.h>
using namespace std;

void minLenSubarray(vector<int> arr, int n, int target){
    int left = 0;
    int right = 0;
    int sum = 0;
    int minLen = INT_MAX;
    while(right<n)
    {
        sum += arr[right];
        while(sum >= target){
            
            minLen = min(minLen,right-left +1);
            sum -= arr[left];
            left++;
        }
        right++;
    } 
    cout<<minLen;
}

int main()
{
    vector<int> arr = {2,3,1,2,4,3};
    int n = arr.size();
    int target = 7;
    minLenSubarray(arr,n, target);
    return 0;
}
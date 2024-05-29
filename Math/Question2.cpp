#include<bits/stdc++.h>
using namespace std;

vector<int> incrementLastNo(vector<int> nums){
    int n = nums.size();
    nums[n-1]++;
    for (int i = n-1; i > 0; i--)
    {
        if(nums[i]>=10){
            nums[i]-=10;
            nums[i-1]++;
        }
    }
    //check the first integer of the array
    if(nums[0]>=10){
        nums[0]-=10;
        nums.insert(nums.begin(),1); //append the digit at the beginning
    }
    return nums;
}

int main()
{
    vector<int> nums = {8,9,9};
    vector<int> result = incrementLastNo(nums);
    cout<<"original array: ";
    for(int n: nums){
        cout<<n<<" ";
    }
    cout<<"\nAfter increment last digit: ";
    for(int n: result){
        cout<<n<<" ";
    }
}
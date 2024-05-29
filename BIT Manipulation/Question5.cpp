#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> nums){
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        int mask = 1<<i;
        for(int num: nums){
            if(num&mask){
                count++;
            }
        }
        if(count%3!=0){
            result |= mask;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {2,3,2,3,2,7,3};
    int result = singleNumber(nums);
    cout<<"single number is: "<<result;
    return 0;
}
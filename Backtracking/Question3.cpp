#include<bits/stdc++.h>
using namespace std;

void generatePermutations(int idx, vector<int>& nums, vector<vector<int>>& result){
    if(idx==nums.size()){
        result.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx],nums[i]);
        generatePermutations(idx+1,nums,result);
        swap(nums[idx],nums[i]);
    }
    
}
vector<vector<int>> permute(vector<int> nums){
    vector<vector<int>> result;
    generatePermutations(0,nums,result);
    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> permutations = permute(nums);
    for(auto x: permutations){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
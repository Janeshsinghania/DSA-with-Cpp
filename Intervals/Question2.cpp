#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> nums){
    if(nums.empty()){
        return {};
    }
    sort(nums.begin(),nums.end());
    int n = nums.size(); 
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        if(res.empty()){
            res.push_back(nums[i]);
        }
        else{
            vector<int> &a = res.back();
            int y = a[1];
            //overlapping condition
            if(nums[i][0]<=y){
                a[1] = max(y,nums[i][1]);
            }
            //non overlapping condition
            else{
                res.push_back(nums[i]);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> nums = {{1,3},{2,6},{4,10},{15,18}};
    vector<vector<int>> result = mergeIntervals(nums);
    for(auto i: result){
        for(auto x:i){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
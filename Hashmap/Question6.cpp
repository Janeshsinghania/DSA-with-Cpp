#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int target){
    vector<int> ans;
    unordered_map<int,int> mp;
    int n =arr.size();
    for (int i = 0; i < n; i++)
    {
        if(mp.find(target-arr[i])!=mp.end()){
            ans.push_back(mp[target-arr[i]]);
            ans.push_back(i);
        }
        else{
            mp[arr[i]] = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,7,11,15};
    int target = 13;
    vector<int> res = twoSum(arr,target);
    for(auto x: res){
        cout<<x<<" ";
    }
    return 0;
}
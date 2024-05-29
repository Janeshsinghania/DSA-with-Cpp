#include<bits/stdc++.h>
using namespace std;

void findCombinations(vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result, int start){
    if(target==0){
        result.push_back(temp);
        return;
    }
    if(target<0){
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        findCombinations(candidates,target-candidates[i],temp,result,i);
        temp.pop_back();
    }
    
}

vector<vector<int>> combinationSum(vector<int>& candidates , int target){
    vector<vector<int>> result;
    vector<int> temp;
    findCombinations(candidates,target,temp,result,0);
    return result;
}

int main()
{
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates,target);
    for(auto x: result){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
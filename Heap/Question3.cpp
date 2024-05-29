#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> nums1, vector<int> nums2, int k){
    vector<vector<int>> result;
    priority_queue<pair<int,pair<int,int>>> pq;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            int sum = nums1[i] + nums2[j];
            if(pq.size()<k){
                pq.push({sum,{nums1[i],nums2[j]}});
            }
            else if(sum<pq.top().first){
                pq.pop();
                pq.push({sum,{nums1[i],nums2[j]}});
            }
            else{
                break;
            }
        } 
    }
    while(!pq.empty()){
        result.push_back({pq.top().second.first,pq.top().second.second});
        pq.pop();
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    int k = 3;
    vector<vector<int>> result = kSmallestPairs(nums1,nums2,k);
    for(auto x: result){
        for(auto y: x){
            cout<<y<<" ";
        }cout<<endl;
    }
}
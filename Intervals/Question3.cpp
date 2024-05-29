#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals, vector<int> newInterval){
    vector<vector<int>> res;
    int n = intervals.size();
    int i = 0;
    while(i<n && intervals[i][1] < newInterval[0]){
        res.push_back(intervals[i]);
        i++;
    }
    while (i<n && newInterval[1] > intervals[i][0])
    {
        newInterval[0] = min(newInterval[0] , intervals[i][0]);
        newInterval[1] = max(newInterval[1] , intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i<n)
    {
        res.push_back(intervals[i]);
        i++;
    }
    
    return res;
}

int main()
{
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> result = mergeIntervals(intervals,newInterval);
    for(auto x: result){
        for(auto z: x){
            cout<<z<<" ";
        }
        cout<<endl;
    }
}
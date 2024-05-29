#include<bits/stdc++.h>
using namespace std;

vector<int> canFinish(int numCourses, vector<vector<int>> prerequisites){
    vector<int> ans;
    vector<int> inDegree(numCourses,0);
    unordered_map<int,vector<int>> mp;
    for(auto x: prerequisites){
        mp[x[1]].push_back(x[0]);
        inDegree[x[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto x: mp[temp]){
            inDegree[x]--;
            if(inDegree[x]==0){
                q.push(x);
            }
        }
    }
    if(ans.size()!= numCourses){
        return {};
    }
    return ans;
}

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};

    vector<int> order = canFinish(numCourses,prerequisites);
    for(auto x:order){
        cout<<x<<" ";
    }
    return 0;
}
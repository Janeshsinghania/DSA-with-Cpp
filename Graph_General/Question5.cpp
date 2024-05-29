#include<bits/stdc++.h>
using namespace std;

bool canfinish(int numcourses, vector<vector<int>> prerequisites){
    vector<int> inDegree(numcourses,0);
    unordered_map<int,vector<int>> mp;
    for (auto a: prerequisites)
    {
        mp[a[1]].push_back(a[0]);
        inDegree[a[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numcourses; i++)
    {
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(auto x: mp[temp]){
            inDegree[x]--;
            if(inDegree[x]==0){
                q.push(x);
            }
        }
    }
    
    for (int i = 0; i < numcourses; i++)
    {
        if(inDegree[i]>0){
            return false;
        }
    }
    return true;
}

int main()
{
    int numcourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    if(canfinish(numcourses,prerequisites)){
        cout<<"You can finish all courses";
    }else{
        cout<<"You cannot finish all courses";
    }
    return 0;
}
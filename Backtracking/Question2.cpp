#include<bits/stdc++.h>
using namespace std;

void solve(int n, int k, int start, vector<int>& temp, vector<vector<int>>& result){
    if(k==0){
        result.push_back(temp);
        return;
    }
    for (int i = start; i <= n; i++)
    {
        temp.push_back(i);
        solve(n,k-1,i+1,temp,result);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k){
    vector<vector<int>> result;
    vector<int> temp;
    solve(n,k,1,temp,result);
    return result;
}

int main()
{
    int n = 4;
    int k = 3;
    vector<vector<int>> combination = combine(n,k);
    for(auto x: combination){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
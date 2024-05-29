#include<bits/stdc++.h>
using namespace std;

double dfs(string A,string B, unordered_map<string,unordered_map<string,double>> mp, unordered_set<string> &visited){
    if(mp[A].find(B)!=mp[A].end()){
        return mp[A][B]; 
    }
    
    for(auto ch: mp[A]){
        if(visited.find(ch.first)==visited.end()){
            visited.insert(ch.first);
            double val = dfs(ch.first,B,mp,visited);
            if(val){
                mp[A][B] = ch.second*val;
                return mp[A][B];
            }
        }
    }
    return 0;
}

vector<double> calEquation(vector<vector<string>> equations, vector<double> values, vector<vector<string>> queries){
    unordered_map<string,unordered_map<string,double>> mp;
    vector<double> ans;
    for (int i = 0; i < equations.size(); i++)
    {
        mp[equations[i][0]][equations[i][1]] = values[i];
        mp[equations[i][1]][equations[i][0]] = (double) 1/(values[i]);
    }
    
    for (int i = 0; i < queries.size(); i++)
    {
        unordered_set<string> visited;
        double val = dfs(queries[i][0],queries[i][1],mp,visited);
        if(!val){
            ans.push_back(-1.0);
        }else{
            ans.push_back(val);
        }
    }
    return ans;
}

int main()
{
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> result = calEquation(equations,values,queries);
    for(auto x: result){
        cout<<x<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void helper(string current, vector<string>& result , int open, int closed, int n){
    if(open==n && closed==n){
        result.push_back(current);
        return;
    }
    if(open<n){
        helper(current + "(", result,open+1,closed,n);
    }
    if(closed<n && closed<open){
        helper(current + ")", result,open,closed+1,n);
    }
}

vector<string> generateCombination(int n){
    vector<string> result;
    helper("",result,0,0,n);
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<string> solutions = generateCombination(n);
    for(auto x: solutions){
        cout<<x<<endl;
    }
}
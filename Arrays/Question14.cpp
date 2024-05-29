#include<bits/stdc++.h>
using namespace std;

void canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    int n = gas.size();
    int totalgas = 0;
    int currgas = 0;
    int Startingindex = 0;
    for (int i = 0; i < n; i++)
    {
        totalgas += gas[i] - cost[i];
        currgas += gas[i] - cost[i];

        if(currgas<0){
            currgas = 0;
            Startingindex = i+1;
        }
    }
    if(totalgas>=0){
        cout<<Startingindex;
    }else{
        cout<<"-1";
    }
    
}

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    canCompleteCircuit(gas,cost);
}
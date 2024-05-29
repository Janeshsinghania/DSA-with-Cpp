#include<bits/stdc++.h>
using namespace std;

int calMutations(string startGene, string endGene, vector<string> bank){
    unordered_set<string> bankSet(bank.begin(),bank.end());
    if(bankSet.find(endGene)==bankSet.end()){
        return -1;
    } 
    queue<pair<string,int>> q;
    q.push({startGene,0});
    while (!q.empty())
    {
        string node = q.front().first;
        int mutations = q.front().second;
        q.pop();
        if(node==endGene){
            return mutations;
        }
        for (int i = 0; i < startGene.size(); i++)
        {
            char original = node[i];
            for(char ch: "ACGT"){
                node[i] = ch;
                if(bankSet.find(node)!=bankSet.end()){
                    q.push({node,mutations+1});
                    bankSet.erase(node);
                }
            }
            node[i] = original;
        }
        
    }
    return -1;
}

int main()
{
    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    int result = calMutations(startGene,endGene,bank);
    cout<<"Minimum mutations: "<<result;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool containDuplicate(vector<int> num, int k){
    unordered_map<int,int> mp;
    for (int i = 0; i < num.size(); i++)
    {
        if(mp.count(num[i])>0 && abs(mp[num[i]] - i) <= k){
            return true;
        }
        mp[num[i]] = i;
    }
    return false;
}

int main()
{
    vector<int> num = {1,2,3,1};
    int k = 3;
    bool result = containDuplicate(num,k);
    if (result){
        cout<<"true";
    }else{
        cout<<"false";
    }
}
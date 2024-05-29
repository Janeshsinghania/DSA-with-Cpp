#include<bits/stdc++.h>
using namespace std;

void sum(vector<int> arr, int n){
    set<vector<int>> result;
    sort(arr.begin() , arr.end());
    for (int i = 0; i < n-2; i++)
    {
        int j = i+1;
        int k = n-1;
        while(j<k){
            if((arr[i] + arr[j] + arr[k]) < 0){
                j++;
            }
            else if((arr[i] + arr[j] + arr[k]) > 0){
                k--;
            }
            else{
                result.insert({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }
        }
    }
    for (auto a:result)
    {
        for (auto x: a)
        {
           cout<<x<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    int n = arr.size();
    sum(arr,n);
    return 0;
}
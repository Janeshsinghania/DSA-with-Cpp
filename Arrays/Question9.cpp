#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &arr, int n){
    int Reach = 0;
    for (int i = 0; i < n; i++)
    {
        if(i>Reach){
            return false;
        }
        Reach = max(Reach,i+arr[i]);
        if(Reach>=n-1){
            return true;
        }
    }
    return false;
    
}

int main()
{
    vector<int> arr = {2,3,1,1,4};
    int n = arr.size();
    bool ans = canJump(arr,n);
    if(ans){
        cout<<"true";
    }else{
        cout<<"false";
    }
}
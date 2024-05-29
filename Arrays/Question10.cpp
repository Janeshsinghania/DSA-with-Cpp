#include<bits/stdc++.h>
using namespace std;

int jumps(vector<int> &arr, int n){
    if(n==1){
        return 0;
    }
    int Jumps = 0;
    int currpos = 0;
    int maxpos = 0;
    for (int i = 0; i < n-1; i++)
    {
        maxpos = max(maxpos,i+arr[i]);
        if(i==currpos){
            currpos = maxpos;
            Jumps++;
        }
    }
    return Jumps;
    
}


int main()
{
    vector<int> arr = {2,3,1,1,4};
    int n = arr.size();
    int minjump = jumps(arr,n);
    cout<<minjump;
}
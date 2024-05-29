#include<bits/stdc++.h>
using namespace std;

void candy(vector<int> arr, int n){
    vector<int> candies(n,1);
    int totalcandy = 0;
    for (int i = 1; i <= n; i++)
    {
        if(arr[i] > arr[i-1]){
            candies[i] = candies[i-1] + 1;
        }
    }

    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i]>arr[i+1]){
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        totalcandy += candies[i];
    }
    cout<<totalcandy;
    
    
    
}

int main()
{
    vector<int> arr = {1,2,2};
    int n = arr.size();
    candy(arr,n);
}
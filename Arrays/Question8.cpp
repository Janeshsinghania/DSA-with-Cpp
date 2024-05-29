#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    int profit = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]<arr[i+1]){
            profit += (arr[i+1]-arr[i]);
        }
    }
    cout<<profit;
    
}
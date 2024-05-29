#include<bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &arr, int n){
    int i ;
    sort(arr.begin(), arr.end());
    for ( i = 1; i <= n; i++)
    {
        if(arr[n-i]<i){
            break;
        }
    }
    return i-1;
    
    
}

int main()
{
    vector<int> arr = {3,5,0,6,2};
    int n = arr.size();
    int result = hIndex(arr,n);
    cout<<result;
}
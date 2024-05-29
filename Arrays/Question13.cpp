#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> arr, int n){
    vector<int> result(n,1);
    int prefix = 1, suffix = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] *= prefix;
        prefix *= arr[i];
    }
    for (int i = n-1; i>=0; i--)
    {
        result[i] *= suffix;
        suffix *= arr[i];
    }
    return result;
    
}

int main()
{
    vector<int> arr = {1,2,3,4};
    int n = arr.size();
    vector<int> result = productExceptSelf(arr,n);

    for (auto i: result)
    {
        cout<<i<<" ";
    }
    

}
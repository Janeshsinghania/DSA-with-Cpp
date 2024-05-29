#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,2,2,3,4,5,5,6};
    int n = arr.size();
    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=arr[i+1]){
            arr[pos++] = arr[i];
        }
    }
    for (int i = 0; i < pos; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}
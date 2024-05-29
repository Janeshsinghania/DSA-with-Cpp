#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-1,-100,99,3};
    int n = arr.size();
    vector<int> temp(n,0);
    int key;
    cin>>key;
    for (int i = 0; i < n ; i++)
    {
        temp[(i+key)%n] = arr[i];
    }
    // for (int i = n-key; i < n; i++)
    // {                                            another method
    //     temp[pos++] = arr[i];
    // }
    for (int i = 0; i < temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }
    
    
    
    
    
}
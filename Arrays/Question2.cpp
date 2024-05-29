#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3,2,4,3,8,7};
    int pos = 0;
    int value;
    cin>>value;   //to remove from the array 

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]!=value){
            arr[pos++] = arr[i];
            
        }
    }
    for (int i = 0; i < pos; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}
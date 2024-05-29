#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3,6,2,1,4,2,1,5};
    sort(arr.begin(),arr.end());
    int pos = 0;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(count<2 || arr[count-2]!=arr[i]){
            arr[count++] = arr[i];
        }
    }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if(arr[i]==arr[i+1] && arr[i+1] == arr[i+2]){     another method
    //         continue;
    //     }
    //     else{
    //         arr[pos++] = arr[i];
    //     }
    // }
    
    

    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}
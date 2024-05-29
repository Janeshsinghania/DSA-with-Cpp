#include<bits/stdc++.h>
using namespace std;

void sum(vector<int> arr, int target){
    int x=0 , y = arr.size() -1;
    while(x<y){
        if(arr[x] + arr[y] == target){
            cout<<x+1<<" "<<y+1;
        }
        if(arr[x] + arr[y]< target){
            x++;
        }
        else{
            y--;
        }
    } 
}

int main()
{
    vector<int> arr = {2,7,11,15};
    int target = 18;
    sum(arr,target);

    return 0;
}
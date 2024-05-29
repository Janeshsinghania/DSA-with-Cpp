#include<bits/stdc++.h>
using namespace std;

void waterContainer(vector<int> arr){
    int i = 0;
    int j = arr.size()-1;
    int maxWater = 0;
    while (i<j)
    {
        int currArea = min(arr[i], arr[j]) * (j-i);
        maxWater = max(maxWater, currArea);

        if(arr[i]<arr[j]){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<maxWater;
}

int main()
{
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    waterContainer(arr);

    return 0;
}
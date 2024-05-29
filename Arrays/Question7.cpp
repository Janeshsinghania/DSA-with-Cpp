#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {7,1,5,3,6,4};
    int n = arr.size();
    int minimum = arr[0];           //another method is to make another temp vector and
    int maxProfit = 0;              //add the max value of arr in temp i.e start from n-2
                                    //then subtract temp[i]-arr[i]
    for (int i = 1; i < n; i++)
    {
        maxProfit= max(maxProfit,arr[i]-minimum);
        minimum = min(minimum,arr[i]);
    }
    cout<<maxProfit;
    
}
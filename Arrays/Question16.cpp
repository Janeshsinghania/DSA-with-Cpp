#include<bits/stdc++.h>
using namespace std;

void trappingWater(vector<int> height, int n){
    vector<int> left(n,0);
    vector<int> right(n,0);
    left[0] = height[0];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1], height[i]);
    }

    right[n-1] = height[n-1];
    for (int i = n-2; i >=0; i--)
    {
        right[i] = max(right[i+1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }
    cout<<ans;
    
    
}

int main()
{
    vector<int> height = {4,2,0,3,2,5};
    int n = height.size();
    trappingWater(height,n);
}
#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> points){
    int n = points.size();
    int count = 0;
    if(n<=2){
        return n;
    }
    for (int i = 0; i < n; i++)
    {
        unordered_map<double,int> mp;
        for (int j = i+1; j < n; j++)
        {
            if(points[i][0]==points[j][0]){
                mp[10001]++;
            }
            else{
                double slope = (double)(points[j][1]-points[i][1]) / double(points[j][0]-points[i][0]);
                mp[slope]++;
            }
        }
        for(auto x:mp){
            count = max(count,x.second+1);
        }
    }
    return max(1,count);
}

int main()
{
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 1}};
    cout<<"maximum no of points on the same straight line: "<<maxPoints(points);
    return 0;
}
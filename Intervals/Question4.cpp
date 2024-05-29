#include<bits/stdc++.h>
using namespace std;

int countArrows(vector<vector<int>> points){
    int n = points.size();
    int count = 1;
    sort(points.begin(),points.end());
    int end = points[0][1];
    for (int i = 0; i < n; i++)
    {
        if(points[i][0] > end){
            count++;
            end = points[i][1];
        }else{
            end = min(end,points[i][1]);
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int minArrows = countArrows(points);
    cout<<"Min no of arrows to burst ballons:"<<minArrows;
    return 0;
}
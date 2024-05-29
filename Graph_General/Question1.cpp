#include<bits/stdc++.h>
using namespace std;

void adjacent(vector<vector<char>>& grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0'){
        return;
    }
    grid[i][j] = '0';
    adjacent(grid,i+1,j);
    adjacent(grid,i-1,j);
    adjacent(grid,i,j+1);
    adjacent(grid,i,j-1);
}

int numIslands(vector<vector<char>> grid){
    if(grid.empty() || grid[0].empty()){
        return 0;
    }
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j]=='1'){
                count++;
                adjacent(grid,i,j);
            }
        } 
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int result = numIslands(grid);
    cout<<"No of islands in given matrix:"<<result;
    return 0;
}
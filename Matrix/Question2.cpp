#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> matrix){
    vector<int> result;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0 , left = 0;
    int bottom = rows - 1;
    int right = cols - 1;
    while(left<=right && top<=bottom){
        //traverse top row
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;
        //traverse last column
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;
        //traverse bottom row
        if(top<=bottom){
            for (int i = right; i >= left; --i)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        //traverse left column
        if(left<=right){
            for (int i = bottom; i >= top; --i)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = spiralOrder(matrix);
    for (auto a:result)
    {
        cout<<a<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        if(matrix[i][0]==0){
            col0 = 0;
        }
        for (int j = 1; j < m; j++)
        {
            if(matrix[i][j]==0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }  
    }
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 1; j--)
        {
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
        if(col0 == 0){
            matrix[i][0] = 0;
        }
    } 
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    cout<<"original vector:"<<endl;
     
    setZeroes(matrix);
    cout<<"Matrix with zero set:"<<endl;
    for (auto num: matrix)
    {
        for(auto x: num){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;   
}
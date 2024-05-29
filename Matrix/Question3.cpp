#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        } 
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout<<"original matrix:"<<endl;
    for (auto num: matrix)
    {
        for(auto x: num){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    rotate(matrix);

    cout<<"after rotating matrix"<<endl;
    for (auto num: matrix)
    {
        for(auto x: num){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
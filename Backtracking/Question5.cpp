#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& board, int row, int col, int n){
    for (int i = 0; i < n; i++)
    {
        if(board[i][col]==1){
            return false;
        }
    }
    //left diagonal
    int x= row;
    int y = col;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--; 
        y--;
    }
    //right diagonal
    x = row;
    y = col;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--; 
        y++;
    }
    return true;
}

int solveNQueens(vector<vector<int>>& board, int n, int i){
    if(i==n){
        return 1;
    }
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if(isValid(board,i,j,n)){
            board[i][j] = 1;
            count += solveNQueens(board,n,i+1);
            board[i][j] = 0;
        }
    }
    return count;
}

int totalNQueens(int n){
    vector<vector<int>> board(n,vector<int>(n));
    return solveNQueens(board,n,0);
}

int main()
{
    int n;
    cin>>n;
    int solutions = totalNQueens(n);
    cout<<"No of distinct solutions: "<<solutions;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &board, int i, int j){
    board[i][j] = '*';
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};   //4 adjacent directions
    for (int k = 0; k < 4; k++)
    {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if(cx>=0 && cx<board.size() && cy>=0 && cy<board[0].size() && board[cx][cy]=='O'){
            change(board,cx,cy);
        }
    }
    
}

void solveBoard(vector<vector<char>> &board){
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(board[i][j]=='O'){
                    change(board,i,j);
                }
            }
        }  
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j]=='O'){
                board[i][j]='X';
            }
        }  
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j]=='*'){
                board[i][j]='O';
            }
        }   
    } 
}

int main()
{
    vector<vector<char>> board = {
        {'O', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    solveBoard(board);
    for(auto row: board){
        for(auto col: row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}
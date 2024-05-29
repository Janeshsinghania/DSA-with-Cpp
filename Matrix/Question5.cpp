#include<bits/stdc++.h>
using namespace std;

int countNeighbours(vector<vector<int>> &temp, int row, int col){
    vector<int> dx = {0,0,1,1,1,-1,-1,-1};
    vector<int> dy = {1,-1,1,-1,0,0,1,-1};
    int count = 0;
    int n = temp.size();
    int m = temp[0].size();
    for (int i = 0; i < 8; i++)
    {
        int nrow = dx[i] + row;
        int ncol = dy[i] + col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && temp[nrow][ncol]==1){
            count++;
        }
    }
    return count;
}

void lifeOfGame(vector<vector<int>> &board){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> temp = board;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(countNeighbours(temp,i,j)<2 || countNeighbours(temp,i,j)>3){
                board[i][j] = 0;
            }
            else if(countNeighbours(temp,i,j)==3 && board[i][j]==0){
                board[i][j] = 1;
            }
            else if((countNeighbours(temp,i,j)==2 || countNeighbours(temp,i,j)==3) && board[i][j]==1){
                board[i][j] = 1;
            }
        }
        
    }
    
}

int main()
{
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };
    cout<<"original vector:"<<endl;
    for (auto num: board)
    {
        for(auto x: num){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    lifeOfGame(board);
    cout<<"after changing into life of game:"<<endl;
    for (auto num: board)
    {
        for(auto x: num){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
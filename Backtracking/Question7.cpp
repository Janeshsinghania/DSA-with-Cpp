#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string word,int i, int j, int k, int n, int m){
    if(k==word.size()){
        return true;  
    }
    if(i==n||i<0||j==m||j<0||word[k]!=board[i][j]){
        return false;
    }
    char ch = board[i][j];
    board[i][j] = '#';

    bool ch1 = dfs(board,word,i+1,j,k+1,n,m);
    bool ch2 = dfs(board,word,i-1,j,k+1,n,m);
    bool ch3 = dfs(board,word,i,j+1,k+1,n,m);
    bool ch4 = dfs(board,word,i,j-1,k+1,n,m);

    board[i][j] = ch; //backtrack
    return ch1||ch2||ch3||ch4;

}



bool isValid(vector<vector<char>>& board, string word){
    if(board.empty() || board[0].empty()){
        return false;
    }
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            if(dfs(board,word,i,j,0,n,m)){
                return true;
            }
        }
    }
    return false;

}

int main()
{
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    bool result = isValid(board,word);
    if(result){
        cout<<"Word is present";
    } 
    else{
        cout<<"Wrong word";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int snakeAndLadder(vector<vector<int>> board){
    int n = board.size();
    vector<int> flatboard(n*n);
    int idx = 0;
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            flatboard[idx++] = board[i][j];
        }
    }
    queue<int> q;
    unordered_set<int> visited;
    q.push(0);
    visited.insert(0);
    int moves = 0;
    while (!q.empty())
    {
        int k = q.size();
        for (int i = 0; i < k; i++)
        {
            int temp = q.front();
            q.pop();
            if(temp == n*n-1){
                return moves;
            }
            for (int j=1; j<=6 && temp+j<n*n ; j++)
            {
                int next = temp + j;
                if(flatboard[next]!= -1){
                    next = flatboard[next] - 1;
                }
                if(visited.find(next) == visited.end()){
                    q.push(next);
                    visited.insert(next);
                }
            }
            
        }
        moves++;
    }
    return -1;
}

int main()
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };
    int result = snakeAndLadder(board);
    cout<<"Min no of moves to reach the end: "<<result;
    return 0;
}
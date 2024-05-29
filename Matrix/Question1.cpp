#include<bits/stdc++.h>
using namespace std;

bool solveSuduko(vector<vector<char>> &a){
    bool m1[9][9] = {0} , m2[9][9] = {0}, m3[9][9] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(a[i][j]!='.'){
                int num = a[i][j] - '0' -1;
                int k = i/3 * 3 + j/3;
                if(m1[i][num] || m2[num][j] || m3[k][num]){
                    return false;
                }
                m1[i][num] = m2[num][j] = m3[k][num] = 1;
            }
        } 
    }
    return true;
}

int main()
{
    vector<vector<char>> suduku ={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };
    bool result = solveSuduko(suduku);
    if(result){
        cout<<"valid sukudo";
    }
    else{
        cout<<"invalid sukudo";
    }
    return 0;
}
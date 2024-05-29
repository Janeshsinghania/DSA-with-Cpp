#include<bits/stdc++.h>
using namespace std;

bool checkMatrix(vector<vector<int>> matrix, int target){
    int n = matrix.size();
    int m =matrix[0].size();
    int left = 0;
    int right = n*m-1;
    while(left<=right){
        int mid = (left+right)/2;
        int midElement = matrix[mid/n][mid%n];  //convert 1D matrix into 2D matrix;
        if(midElement==target){
            return true;
        }
        else if(midElement<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,6},{9,10,12,13},{14,16,18,19},{21,23,24,25}};
    int target = 17;
    bool result = checkMatrix(matrix,target);;
    cout<<(result? "element found" : "element not found");
    return 0;
}
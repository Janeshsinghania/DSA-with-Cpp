#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int n, vector<int> &B, int m){
    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;

    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k] = A[i];
            k--;
            i--;
        } else {
            A[k] = B[j];
            k--;
            j--;
        }
    }

    while (j >= 0) {
        A[k] = B[j];
        k--;
        j--;
    }
    // Print the merged array
    for (int i = 0; i < n + m; i++) {
        cout << A[i] << " ";
    }
}

int main(){
    vector<int> A = {1,2,3};
    vector<int> B = {2,5,6};
    int n = A.size();
    int m = B.size();
    
    merge(A, n, B, m);

    

    return 0;
}

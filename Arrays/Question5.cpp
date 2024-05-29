#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {1,1,1,2,1,2,2};
    sort(A.begin(), A.end());

    int n = A.size();
    cout<<A[n/2];   //for majority element
}
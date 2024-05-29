#include<bits/stdc++.h>
using namespace std;

void lastWord(string A){
    int n = A.size();
    int count = 0;
    bool flag = false;
    for (int i = n-1; i>=0; i--)
    {
        if(A[i]==' ' && flag){
            break;
        }
        if(A[i]!= ' '){
            count++;
            flag = true;
        }
    }
    cout<<count;
}

int main()
{
    string A = "Are you a bowler";
    lastWord(A);

    return 0;
}
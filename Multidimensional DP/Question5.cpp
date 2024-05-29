#include<bits/stdc++.h>
using namespace std;

bool isInterleaveRecursive(string s1, string s2, string s3, int i, int j, vector<vector<int>>& memo) {
    // Base case: If we have reached the end of all strings
    if (i == s1.length() && j == s2.length()) {
        return true;
    }
    
    // Check if the result is already computed
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    
    // Recursive case: If the current character of s3 matches with s1, recurse for the next character of s1
    if (i < s1.length() && s1[i] == s3[i + j]) {
        memo[i][j] = isInterleaveRecursive(s1, s2, s3, i + 1, j, memo);
        if (memo[i][j]) {
            return true;
        }
    }
    
    // Recursive case: If the current character of s3 matches with s2, recurse for the next character of s2
    if (j < s2.length() && s2[j] == s3[i + j]) {
        memo[i][j] = isInterleaveRecursive(s1, s2, s3, i, j + 1, memo);
        if (memo[i][j]) {
            return true;
        }
    }
    
    // If none of the above conditions are met, mark the result as false
    memo[i][j] = false;
    return false;
}

bool isInterleave(string s1, string s2, string s3) {
    // Create a memoization table initialized with -1
    vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    // Call the recursive function starting from index 0 for both strings
    return isInterleaveRecursive(s1, s2, s3, 0, 0, memo);
}

int main() {
    string s1 = "abc";
    string s2 = "def";
    string s3 = "adbecf";

    if (isInterleave(s1, s2, s3)) {
        cout << "Yes, " << s3 << " is formed by interleaving of " << s1 << " and " << s2 << endl;
    } else {
        cout << "No, " << s3 << " is not formed by interleaving of " << s1 << " and " << s2 << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void firstOccurence(string haystack, string needle){
    int m = haystack.size();
    int n = needle.size();
    for (int i = 0; i <= m-n; i++)
    {
        if(haystack.substr(i,n) == needle){
            cout<<i<<" ";
        }
    }
    
}

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    firstOccurence(haystack, needle);
    return 0;
}
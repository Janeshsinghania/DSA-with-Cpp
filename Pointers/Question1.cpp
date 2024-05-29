#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    int start = 0;
    int end = s.size() - 1;
    while (start<=end)
    {
        if(!isalnum(s[start])){
            start++;
            continue;
        }
        if(!isalnum(s[end])){
            end--;
            continue;
        }
        if(tolower(s[start]) != tolower(s[end])){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    if(palindrome(s)){
        cout<<"palindrome string";
    }else{
        cout<<"Not a palindrome string";
    }
}
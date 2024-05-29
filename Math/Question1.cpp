#include<bits/stdc++.h>
using namespace std;

bool palindrome(int digit){
    int temp = digit;
    int reversed = 0;
    while(temp>0){
        reversed = reversed*10 + temp%10;
        temp = temp/10;
    }
    return reversed==digit;
}

int main()
{
    int digit = 1221;
    bool result = palindrome(digit);
    cout<<(result? "palindrome digit" : "not a palindrome digit");
    return 0;
}
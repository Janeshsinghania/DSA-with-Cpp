#include<bits/stdc++.h>
using namespace std;

void backtrack(string& digits, int index, unordered_map<char,string>& digitToLetters, string& currentCombination, vector<string>& result){
    if(index == digits.size()){
        result.push_back(currentCombination);
        return;
    }
    char currentDigit = digits[index];
    string letters = digitToLetters.at(currentDigit);
    for(auto ch: letters){
        currentCombination.push_back(ch);
        backtrack(digits, index+1, digitToLetters,currentCombination,result);
        //backTrack
        currentCombination.pop_back();
    }

}

vector<string> letterCombination(string digits){
    vector<string> result;
    if(digits.empty()){
        return result;
    }
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string currentCombination;
    backtrack(digits,0,digitToLetters,currentCombination,result);
    return result;
}

int main()
{
    string digits = "23";
    vector<string> result = letterCombination(digits);
    cout<<"Letter combinations are: ";
    for(auto word: result){
        cout<<word<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList){
    unordered_set<string> wordSet(wordList.begin(),wordList.end());
    if(wordSet.find(endWord)==wordSet.end()){
        return -1;
    }
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    while (!q.empty())
    {
        string temp = q.front().first;
        int count = q.front().second;
        q.pop();
        for (int i = 0; i < temp.size(); i++)
        {
            string temp1 = temp;
            for(char ch = 'a'; ch<='z'; ch++){
                temp1[i] = ch;
                if(temp1==endWord){
                    return count + 1;
                }
                if(wordSet.find(temp1)!=wordSet.end()){
                    q.push({temp1,count+1});
                    wordSet.erase(temp1);
                }
            }
        }
        
    }
    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = ladderLength(beginWord, endWord, wordList);
    cout<<"Number of words in sequence: "<<result;
    return 0;
}
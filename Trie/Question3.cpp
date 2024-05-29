#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    unordered_map<char,TrieNode*> children
    
    ;
    bool isEnd;
    TrieNode(){
        isEnd = false;
    }
};

class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* curr = root;
        for(auto ch: word){
            if(curr->children.find(ch)==curr->children.end()){
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }
    TrieNode* getRoot(){
        return root;
    }
};

class WordSearch{
    private:
    void DFS(vector<vector<char>> &board, int i, int j, string currentWord, vector<vector<bool>> &visited
    ,TrieNode* node, vector<string>& result, unordered_set<string>& resultSet){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]){
            return;
        }
        char ch = board[i][j];
        if(node->children.find(ch)==node->children.end()){
            return;
        }
        visited[i][j] = true;
        currentWord += ch;
        node = node->children[ch];
        if(node->isEnd && resultSet.find(currentWord)==resultSet.end()){
            result.push_back(currentWord);
            resultSet.insert(currentWord);
        }
        DFS(board, i + 1, j, currentWord, visited, node, result, resultSet);
        DFS(board, i - 1, j, currentWord, visited, node, result, resultSet);
        DFS(board, i, j + 1, currentWord, visited, node, result, resultSet);
        DFS(board, i, j - 1, currentWord, visited, node, result, resultSet);
        
        visited[i][j] = false;
    }
    public:
    vector<string> findWord(vector<vector<char>> &board, vector<string> &words){
        Trie trie;
        for(auto word: words){
            trie.insert(word);
        }
        vector<string> result;
        unordered_set<string> resultSet;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                DFS(board,i,j,"",visited,trie.getRoot(),result,resultSet);
            }
            
        }
        return result;
    }
};

int main()
{
    WordSearch wordSearch;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> result = wordSearch.findWord(board,words);
    for(auto word: result){
        cout<<word<<" ";
    }
}
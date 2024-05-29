#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    bool isEnd;
    TrieNode(){
        isEnd = false;
    }
};

class WordDictionary{
    private:
    TrieNode* root;
    bool searchNode(string word, TrieNode* node){
        TrieNode* temp = node;
        for(int i = 0; i< word.size(); i++){
            char ch = word[i];
            if(ch=='.'){
                for(auto& child: temp->children){
                    if(searchNode(word.substr(i+1), child.second)){
                        return true;
                    }
                }
                return false;
            }else{
                if(temp->children.find(ch)==temp->children.end()){
                    return false;
                }
                temp = temp->children[ch];
            }
        }
        return temp->isEnd;
    }
    public:
    WordDictionary(){
        root = new TrieNode();
    }
    void addWord(string word){
        TrieNode* curr = root;
        for(auto ch: word){
            if(curr->children.find(ch)==curr->children.end()){
                curr->children[ch] = new TrieNode;
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }

    bool search(string word){
        return searchNode(word,root);
    }
};

int main()
{
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout<<dict.search("pad")<<endl;
    cout<<dict.search("bad")<<endl;
    cout<<dict.search(".ad")<<endl;
    cout<<dict.search("b..")<<endl;
    return 0;

}
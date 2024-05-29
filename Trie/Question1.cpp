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

class Trie{
    private:
    TrieNode* root;
    TrieNode* searchNode(string word){
        TrieNode* current = root;
        for(char ch: word){
            if(current->children.find(ch)==current->children.end()){
                return NULL;
            }
            current = current->children[ch];
        }
        return current;
    } 
    public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* current = root;
        for(char ch: word){
            if(current->children.find(ch)==current->children.end()){
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEnd = true;
    }
    bool search(string word){
        TrieNode* temp = searchNode(word);
        return (temp!=NULL) && (temp->isEnd);
    }
    bool startsWith(string word){
        TrieNode* temp = searchNode(word);
        return (temp!=NULL);
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout<<trie.search("apple")<<endl;
    cout<<trie.search("app")<<endl;
    cout<<trie.startsWith("app")<<endl;
    trie.insert("banana");
    cout<<trie.search("banana");
}
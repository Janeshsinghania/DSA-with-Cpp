#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int Key, int Val){
            key = Key;
            val = Val;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;

    }
    int get(int key_){
        if(mp.find(key_)!=mp.end()){
            node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }
    int put(int key_, int value){
        if(mp.find(key_)!=mp.end()){
            node* existnode = mp[key_];
            mp.erase(key_);
            deletenode(existnode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_,value));
        mp[key_] = head->next;
    }
};

int main()
{
    LRUCache lruCache(3);

    lruCache.put(1, 1);
    lruCache.put(2, 2);
    lruCache.put(3, 3);

    cout << lruCache.get(2) << endl; 

    lruCache.put(4, 4);

    cout << lruCache.get(1) << endl; 

    cout << lruCache.get(2) << endl; 
    cout << lruCache.get(3) << endl; 
    cout << lruCache.get(4) << endl; 

    return 0;
}
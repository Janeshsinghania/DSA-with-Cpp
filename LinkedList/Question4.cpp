#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node* random;
    Node(int x){
        val = x;
        next = NULL;
        random = NULL;
    }
};

Node* copyList(Node* head){
    unordered_map<Node*,Node*> mp;
    Node* curr = head;
    while (curr)
    {
        Node* copy = new Node(curr->val);
        mp[curr] = copy;
        curr = curr->next;
    }
    curr = head; 
    while(curr){
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[head];
}

int main()
{
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->random = NULL;         
    head->next->random = head;     
    head->next->next->random = head->next->next->next->next;  
    head->next->next->next->random = head->next;              
    head->next->next->next->next->random = head;

    Node* result = copyList(head);
    while (result)
    {
        cout<<result->val<<","<<(result->random ? result->random->val:-1)<<endl;
        result = result->next;
    }
    
}
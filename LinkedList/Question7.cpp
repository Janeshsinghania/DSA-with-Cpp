#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

Node* removeNode(Node* head, int n){
    if(!head || n<=0){
        return head;
    }
    int count = 0;
    Node* curr = head;
    Node* dum = curr;
    while(curr){
        count++;
        curr = curr->next;
    }
    curr = head;
    int len = count-n-1;
    for (int i = 0; i < len; i++)
    {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return dum;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int n = 2;
    Node* result = removeNode(head,n);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
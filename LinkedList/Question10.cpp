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

Node* partition(Node* head, int x){
    Node* greatHead = new Node(0);
    Node* lessHead = new Node(0);
    Node* greatptr = greatHead;
    Node* lessptr = lessHead;
    while (head)
    {
        if(head->val<x){
            lessptr->next = head;
            lessptr = lessptr->next;
        }else{
            greatptr->next = head;
            greatptr = greatptr->next;
        }
        head = head->next;
    }
    lessptr->next = greatHead->next;
    greatptr->next = NULL;
    return lessHead->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);

    int x = 3;
    Node* result = partition(head,x);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
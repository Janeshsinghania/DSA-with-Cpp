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

Node* reverseK(Node* head, int k){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    int count = 0;
    Node* temp = head;
    for (int i = 0; i < k; i++)
    {
        if(temp==NULL){
            return head;
        }
        temp = temp->next;
    }
    
    while (currptr!=NULL && count<k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reverseK(nextptr,k);
    }
    return prevptr;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 3;
    Node* result = reverseK(head,k);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
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

Node* rotateList(Node* head, int k){
    if(head==NULL || k==0){
        return head;
    }
    Node* temp = head;
    int n = 0;
    while(temp->next){
        temp = temp->next;
        n++;
    }
    k = k%(n+1);
    temp->next = head;
    int jump = n-k;
    temp = head;
    while(jump){
        temp = temp->next;
        jump--;
    }
    Node* newHead = temp->next;
    temp->next = NULL;
    return newHead;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 3;
    Node* result = rotateList(head,k);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
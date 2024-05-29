#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

Node* merge(Node* left, Node* right){
    Node* dummy = new Node(0);
    Node* curr = dummy;
    while (left!=NULL && right!=NULL)
    {
        if(left->val<right->val){
            curr->next = left;
            left = left->next;
        }else{
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }
    if(left!=NULL){
        curr->next = left;
    }
    if(right!=NULL){
        curr->next = right;
    }
    return dummy->next;
}

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sortList(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mid = findMiddle(head);
    //split the node into 2 equal halves
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    //recursively sort both halves
    left = sortList(left);
    right = sortList(right);
    //merge two halves
    return merge(left,right);
}

int main()
{
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    Node* result = sortList(head);
    while (result)
    {
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
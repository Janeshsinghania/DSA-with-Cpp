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

Node* reverseList(Node* &head, int left, int right){
    Node* res = new Node(0);
    Node* pre = res;
    res->next = head;
    for (int i = 0; i < left-1; i++)
    {
        pre = pre->next;
    }
    Node* curr = pre->next;
    for (int i = 0; i < right-left; i++)
    {
        Node* temp = pre->next;
        pre->next = curr->next;
        curr->next = curr->next->next;
        pre->next->next = temp;
    }
    return res->next;
    
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int left = 2;
    int right = 4;

    Node* result = reverseList(head,left,right);
    while (result)
    {
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
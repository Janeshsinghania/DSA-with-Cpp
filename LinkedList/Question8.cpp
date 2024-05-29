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

Node* removeDuplicates(Node* head){
    Node* curr = new Node(0);
    curr->next = head;
    Node* prev = curr;
    while (head)
    {
        if(head->next!=NULL && head->val == head->next->val ){
            while (head->next!=NULL && head->val==head->next->val)
            {
                head = head->next;
            }
            prev->next = head->next;
        }
        else{
            prev = prev->next;
        }
        head = head->next;  
    }
    return curr->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(5);

    Node* result = removeDuplicates(head);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
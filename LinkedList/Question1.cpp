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

bool hasCycle(Node *head){
    Node *fast = head;
    Node *slow = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

int main()
{
    Node* head = new Node(3);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(-4);
    head->next->next->next->next = head->next;
    bool result = hasCycle(head);
    if(result){
        cout<<"cycle detected";
    }else{
        cout<<"no cycle present";
    }
    return 0;
}
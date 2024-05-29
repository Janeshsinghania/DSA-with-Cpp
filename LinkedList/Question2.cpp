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

Node* addTwoNumbers(Node* head1, Node* head2){
    Node* head3 = new Node(0);
    int carry = 0;
    Node* temp = head3;
    while(head1 || head2 || carry){
        int value = head1->val + head2->val + carry;
        carry = value/10;
        head3->next = new Node(value%10);
        head3 = head3->next ;
        head1 = head1->next;
        head2 = head2->next;
    }
    return temp->next;
}

int main()
{
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node* head3 = addTwoNumbers(head1,head2);
    while (head3)
    {
        cout<<head3->val<<" ";
        head3 = head3->next;
    }
    return 0 ;
    
}
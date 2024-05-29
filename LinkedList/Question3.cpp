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

Node* mergeList(Node* head1, Node* head2){
    Node* head3 = new Node(0);
    Node* curr = head3;
    while (head1 && head2)
    {
        if(head1->val < head2->val){
            curr->next = head1;
            head1 = head1->next;
        }else{
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if(head1){
        curr->next = head1;
    }
    if(head2){
        curr->next = head2;
    }
    return head3->next;
}

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(4);

    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(4);

    Node* head3 = mergeList(head1,head2);
    while(head3){
        cout<<head3->val<<" ";
        head3 = head3->next;
    }
    return 0;
}
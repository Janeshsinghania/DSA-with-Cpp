#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

struct CompareNodes{
    bool operator()(Node* a, Node* b){
        return a->val > b->val;
    }
};

Node* sortList(vector<Node*> list){
    priority_queue<Node*,vector<Node*>,CompareNodes> pq;
    for(auto l: list){
        if(l){
            pq.push(l);
        }
    }
    Node* dummy = new Node(0);
    Node* curr = dummy;
    while(!pq.empty()){
        Node* temp = pq.top();
        pq.pop();
        curr->next = temp;
        curr = curr->next;
        if(temp->next){
            pq.push(temp->next);
        }
    }
    return dummy->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(7);

    Node* head1 = new Node(2);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node* head2 = new Node(6);
    head2->next = new Node(9);

    vector<Node*> list = {head,head1,head2};

    Node* result = sortList(list);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}
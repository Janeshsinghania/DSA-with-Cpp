#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int kthElement(Node* root, int& k){
    if(root==NULL){
        return -1;
    }
    int left = kthElement(root->left,k);    //another method is to use stacks
    if(left!=-1){
        return left;
    }
    if(--k==0){
        return root->data;
    }
    int right = kthElement(root->right,k);
    return right;
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    int k = 5;
    int result = kthElement(root,k);
    cout<<result;
    return 0;
}
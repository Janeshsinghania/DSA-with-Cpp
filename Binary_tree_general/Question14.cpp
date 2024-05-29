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

Node* LCA(Node* root, Node* p, Node* q){
    if(root==NULL){
        return NULL;
    }
    if(root==p || root==q){
        return root;
    }
    Node* left = LCA(root->left,p,q);
    Node* right = LCA(root->right,p,q);
    if(left!=NULL && right!=NULL){
        return root;
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* p = root->left;
    Node* q = root->right->right;
    Node* result = LCA(root,p,q);
    cout<<"LCA is:"<<result->data;
    return 0;
}
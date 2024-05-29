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

int countNodes(Node* root){
    if(!root){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
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
    int result = countNodes(root);
    cout<<"No of Nodes is:"<<result;
    return 0;
}
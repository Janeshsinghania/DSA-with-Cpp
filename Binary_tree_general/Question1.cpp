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

int calDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    int l = calDepth(root->left);
    int r = calDepth(root->right);
    int height = max(l,r) + 1;
    return height;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    int result = calDepth(root);
    cout<<result;
    return 0;
}
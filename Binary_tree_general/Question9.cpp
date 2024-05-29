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

bool hasPath(Node* root, int targetSum){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data == targetSum;
    }
    bool leftPath = hasPath(root->left,targetSum-root->data);
    bool rightPath = hasPath(root->right, targetSum - root->data);

    return leftPath || rightPath;
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
    int targetSum = 15;
    bool result = hasPath(root,targetSum);
    cout<<(result?"has path" : "does not contain any path");
    return 0;
}
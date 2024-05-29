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

bool isMirror(Node* root1, Node* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(!root1 || !root2){
        return false;
    }
    return (root1->data==root2->data)&&isMirror(root1->left,root2->right)&&isMirror(root1->right,root2->left);
}

bool isSymmetric(Node* root){
    if(root==NULL){
        return true;
    }
    return isMirror(root->left,root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    if(isSymmetric(root)){
        cout<<"the tree is symmetric";
    }else{
        cout<<"the tree is not symmetric";
    }
    return 0;
}
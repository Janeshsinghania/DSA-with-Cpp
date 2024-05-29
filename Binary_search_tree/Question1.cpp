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

void inorder(Node* root, int& minvalue, int& prevalue){
    if(root==NULL){
        return ;
    }
    inorder(root->left,minvalue,prevalue);
    if(prevalue!=-1){
        minvalue = min(minvalue,abs(root->data - prevalue));
    }
    prevalue = root->data;
    inorder(root->right,minvalue,prevalue);
}

int minDifference(Node* root){
    int minValue = INT_MAX;
    int prevalue = -1;
    inorder(root,minValue,prevalue);
    return minValue;
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(8);
    root->right->right = new Node(5);
    int result = minDifference(root);
    cout<<"Minimum difference between two nodes:"<<result;
    return 0;
}
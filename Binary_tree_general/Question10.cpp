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

int dfs(Node* root, int currentsum){
    if(!root){
        return 0;
    }
    currentsum = currentsum*10 + root->data;
    if(root->left==NULL && root->right==NULL){
        return currentsum;
    }
    int leftsum = dfs(root->left,currentsum);
    int rightsum = dfs(root->right,currentsum);

    return leftsum + rightsum;
}

int calSum(Node* root){
    return dfs(root,0);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int result = calSum(root);
    cout<<"Sum is:"<<result;
    return 0;
}
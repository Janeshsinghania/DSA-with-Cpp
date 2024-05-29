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

int findMaxPath(Node* root, int& maxPath){
    if(!root){
        return 0;
    }
    int leftsum = max(0,findMaxPath(root->left,maxPath));
    int rightsum = max(0,findMaxPath(root->right,maxPath));
    int totalsum = root->data + leftsum + rightsum;
    maxPath = max(maxPath,totalsum);

    return root->data + max(leftsum,rightsum);
}

int maxPathSum(Node* root){
    int maxPath = INT_MIN;
    findMaxPath(root,maxPath);
    return maxPath;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    int result = maxPathSum(root);
    cout<<"maximum path sum is:"<<result;
    return 0;
}
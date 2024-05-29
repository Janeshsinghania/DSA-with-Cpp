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

int search(vector<int> inorder, int st, int en, int curr){
    for (int i = st; i < en; i++)
    {
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(vector<int> preorder, vector<int> inorder, int st, int en){
    static int idx = 0;
    if(st>en){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if(st==en){
        return node;
    }
    int pos = search(inorder,st,en,curr);
    node->left = buildTree(preorder,inorder,st,pos-1);
    node->right = buildTree(preorder,inorder,pos+1,en);
    return node;
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Node* result = buildTree(preorder,inorder,0,4);
    inorderPrint(result);
    return 0;
}
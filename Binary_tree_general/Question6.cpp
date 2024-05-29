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

Node* buildTree(vector<int> postorder, vector<int> inorder, int st, int en){
    static int idx = 4;
    if(st>en){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    Node* node = new Node(val);
    if(st==en){
        return node;
    }
    int pos = search(inorder,st,en,val);
    node->right = buildTree(postorder,inorder,pos+1,en);
    node->left = buildTree(postorder,inorder,st,pos-1);
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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Node* res = buildTree(postorder,inorder,0,4);
    inorderPrint(res);
}
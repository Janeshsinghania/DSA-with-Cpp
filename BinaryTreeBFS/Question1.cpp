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

vector<int> rightSideView(Node* root){
    if(root==NULL){
        return {};
    }
    queue<Node*> q;
    q.push(root);
    vector<int> v;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = n; i > 0; i--)
        {
            Node* temp = q.front();
            q.pop();
            if(i==n){
                v.push_back(temp->data);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            if(temp->left!=NULL){
                q.push(temp->left);
            }
        }   
    }
    return v;
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
    vector<int> result = rightSideView(root);
    for(auto x: result){
        cout<<x<<" ";
    }
}
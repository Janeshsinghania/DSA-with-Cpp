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

vector<vector<int>> zigZagTraversal(Node* root){
    if(root == NULL){
        return {};
    }
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    bool left_to_right = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> v(n);
        for(int i = 0; i<n ; i++)
        {
            Node* temp = q.front();
            q.pop();
            int index = (left_to_right)? i : n-1-i; 
            v[index] = temp->data;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        ans.push_back(v);
        left_to_right = !left_to_right;  
    }
    return ans;
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
    vector<vector<int>> result = zigZagTraversal(root);
    for(auto x:result){
        for(auto i:x){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
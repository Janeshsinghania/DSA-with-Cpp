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

vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> v;
        int n = q.size();
        while (n--)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            v.push_back(temp->data);
        }
        ans.push_back(v);
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
    vector<vector<int>> result = levelOrder(root);
    for(auto x:result){
        for(auto i:x){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
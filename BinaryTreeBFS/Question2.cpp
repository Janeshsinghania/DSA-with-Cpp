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

vector<double> calAverage(Node* root){
    if(root==NULL){
        return {};
    }
    queue<Node*> q;
    q.push(root);
    vector<double> v;
    while (!q.empty())
    {
        int n = q.size();
        int count = 0;
        double levelsum = 0;
        while(n--){
            Node* temp = q.front();
            q.pop();
            levelsum += temp->data;
            count++;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        v.push_back(levelsum/count);
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
    vector<double> result = calAverage(root);
    for(auto x: result){
        cout<<x<<" ";
    }
    return 0;
}
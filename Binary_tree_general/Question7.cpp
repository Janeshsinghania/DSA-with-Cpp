#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

Node* connect(Node* root){
    if(!root){
        return NULL;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        int i = s;
        vector<Node*> arr;
        while(i>0){
            Node* front = q.front();
            q.pop();
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            arr.push_back(front);
            i--;
        }
        i = 0;
        while(i<arr.size()){
            if(i==arr.size()-1){
                arr[i]->next = NULL;
            }else{
                arr[i]->next = arr[i+1];
            }
            i++;
        }
    }
    return root;
}

void serialize(Node* root){
    Node* curr = root;
    while(curr){
        Node* temp = curr;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"#";
        curr = curr->left;
    }
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
    
    Node* result = connect(root);
    serialize(result);
    return 0;
}
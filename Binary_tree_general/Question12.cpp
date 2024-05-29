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

class BSTIterator{
    private:
    stack<Node*> st;
    void pushLeftChild(Node* root){
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        
    }
    public:
    BSTIterator(Node* root){
        pushLeftChild(root);
    }
    int next(){
        Node* temp = st.top();
        st.pop();
        pushLeftChild(temp->right);
        return temp->data;
    }
    bool hasNext(){
        return !st.empty();
    }
};


int main()
{
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator iterator(root);
    while (iterator.hasNext())
    {
        cout<<iterator.next()<<" ";
    }
    return 0;
}
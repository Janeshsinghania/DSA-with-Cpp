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

bool sameTree(Node* root1, Node* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1->data!=root2->data){
        return false;
    }
    if(root1==NULL||root2==NULL){
        return false;
    }
    return sameTree(root1->left,root2->left) && sameTree(root1->right,root2->right);
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    bool result = sameTree(root1,root2);
    if(result){
        cout<<"both trees are identical";
    }else{
        cout<<"both trees are not identical";
    }
}
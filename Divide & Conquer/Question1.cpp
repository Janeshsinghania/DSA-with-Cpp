#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildBST(vector<int>& nums, int left, int right){
    if(left>right){
        return NULL;
    }
    int mid = (left+right)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBST(nums,left,mid-1);
    root->right = buildBST(nums,mid+1,right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums){
    if(nums.empty()){
        return NULL;
    }
    return buildBST(nums,0,nums.size()-1);
}

void inorder(TreeNode* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = sortedArrayToBST(nums);
    cout<<"original array is: "<<endl;
    for(auto x: nums){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"BST array is: "<<endl;
    inorder(root);
    return 0;
}
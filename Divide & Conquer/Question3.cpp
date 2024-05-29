#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    bool val;
    bool isLeaf;
    Node* topleft;
    Node* topright;
    Node* bottomleft;
    Node* bottomright;
    Node(bool v, bool is, Node* tl, Node* tr, Node* bl, Node* br){
        val = v;
        isLeaf = is;
        topleft = tl;
        topright = tr;
        bottomleft = bl;
        bottomright = br;
    }
};

Node* constructQuadTree(vector<vector<int>> grid, int x, int y, int length){
    if(length==1){
        return new Node(grid[x][y]==1,true,NULL,NULL,NULL,NULL);
    }
    int size = length/2;
    Node* topleft = constructQuadTree(grid,x,y,size);
    Node* topright = constructQuadTree(grid,x,y+size,size);
    Node* bottomleft = constructQuadTree(grid,x+size,y,size);
    Node* bottomright = constructQuadTree(grid,x+size,y+size,size);

    if(topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf &&
      topleft->val==topright->val && topright->val==bottomleft->val && bottomleft->val==bottomright->val){
        return new Node(topleft->val,true,NULL,NULL,NULL,NULL);
    }
    else{
        return new Node(true,false,topleft,topright,bottomleft,bottomright);
    }
}

Node* construct(vector<vector<int>> grid){
    return constructQuadTree(grid,0,0,grid.size());
}

void printQuadTree(Node* node){
    if(node==NULL){
        return;
    }
    if(node->isLeaf){
        cout<<"["<<(node->val ? "1":"0" )<< "]";
    }else{
        cout<<"[";
        printQuadTree(node->topleft);
        printQuadTree(node->topright);
        printQuadTree(node->bottomleft);
        printQuadTree(node->bottomright);
        cout<<"]";
    }
}

int main()
{
    vector<vector<int>> grid = {
        {1, 0, 1, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 1}
    };
    Node* root = construct(grid);
    printQuadTree(root);
    return 0;
}
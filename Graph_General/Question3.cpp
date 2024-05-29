#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    vector<Node*> neighbours;
    Node(int val_){
        val = val_;
    }
};

Node* dfs(Node* node, unordered_map<Node*,Node*> &mp){
    vector<Node*> neighbour;
    Node* temp = new Node(node->val);
    mp[node] = temp;
    for(auto it: node->neighbours){
        if(mp.find(it)!=mp.end()){
            neighbour.push_back(mp[it]);
        }
        else{
            neighbour.push_back(dfs(it,mp));
        }
    }
    temp->neighbours = neighbour;
    return temp;
}

Node* cloneBack(Node* node){
    unordered_map<Node*,Node*> mp;
    if(node==NULL){
        return NULL;
    }
    if(node->neighbours.size()==0){
        Node* temp = new Node(node->val);
        return temp;
    }
    return dfs(node,mp);
}

void printNode(Node* node, unordered_map<Node*,bool> &visited){
    if(node==NULL || visited[node]){
        return;
    }
    visited[node] = true;
    cout<<"Node"<<node->val<<"has neighbours:";
    for(Node* temp: node->neighbours){
        cout<<temp->val<<" ";
    }
    cout<<endl;
    for(Node* temp: node->neighbours){
        printNode(temp,visited);
    }
}

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->neighbours.push_back(node2);
    node1->neighbours.push_back(node3);
    node2->neighbours.push_back(node1);
    node2->neighbours.push_back(node3);
    node3->neighbours.push_back(node1);
    node3->neighbours.push_back(node2);

    Node* clonedGraph = cloneBack(node1);
    unordered_map<Node*,bool> visited;
    printNode(clonedGraph,visited);

}
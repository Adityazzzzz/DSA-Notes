#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* right;

    public:
    Node(int data,Node* left1,Node* right1){
        data=data1;
        left=left1;
        right=right1;
    }
};


void mark(unordered_map<Node*,Node*>&parent,Node* root ){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        if(curr->left){
            parent[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right]=curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(Node* root, Node* target, int k) {
    unordered_map<Node*,Node*>parent;
    mark(parent,root);

    unordered_map<Node*,bool>visited;
    queue<Node*>q;

    q.push(target);
    visited[target]=true;
    int count=0;

    while(!q.empty()){
        int size=q.size();
        if(count==k) break;
        count++;
        
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                visited[temp->left]=true;
                q.push(temp->left);
            }
            if(temp->right && !visited[temp->right]){
                visited[temp->right]=true;
                q.push(temp->right);
            }
            if(parent[temp] && !visited[parent[temp]]){
                visited[parent[temp]]=true;
                q.push(parent[temp]);
            }
        }
    }

    vector<int>ans;
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        ans.push_back(curr->val);
    }
    return ans;
}
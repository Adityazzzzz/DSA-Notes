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

// TOP LEVEL VIEW
vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int index = it.second;
            
        if(mpp.find(index) == mpp.end()) mpp[index] = node->data; // imp
            
        if(node->left != NULL) q.push({node->left, index - 1});
        if(node->right != NULL)q.push({node->right, index + 1});
    }

    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}


// BOTTOM LEVEL VIEW 
vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int index = it.second;
            
        mpp[index] = node->data; // imp
            
        if(node->left != NULL) q.push({node->left, index - 1});
        if(node->right != NULL)q.push({node->right, index + 1});
    }

    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}   


// RIGHT SIDE VIEW
void recursion(Node* root, int level, vector<int> &res){
    if(root==NULL) return;
    if(level == res.size()) res.push_back(root->val);
    recursion(root->left, level+1, res);
    recursion(root->right, level+1, res);
}
vector<int>rightside(Node* root){
    vector<int>res;
    recursion(root,0,res);

    return res;
}
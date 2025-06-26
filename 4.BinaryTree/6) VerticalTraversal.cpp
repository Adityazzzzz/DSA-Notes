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


vector<vectpr<int>>vertical(Node* root){
    map<int,map<int,multiset<int>>> mpp;
    queue<pair<Node*,pair<int,int>>> q;
    vector<vector<int>>ans;

    q.push({root,{0,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* temp = it.first;
        int x = it.second.first;
        int y = it.second.second;

        mpp[x][y].insert(temp->val;)
        if(temp->left) q.push({temp->left, {x-1,y+1}});
        if(temp->right) q.push({temp->right, {x+1,y+1}});
    }
    
    for(auto it1 : mpp){
        vector<int>res;
        for(auto it2 : it1.second){
            res.insert(res.end(),res.second.begin(),res.second.end());
        }
        ans.push_back(res);
    }
    return ans
}
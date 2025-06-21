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

vector<vector<int>> zigzag(Node* root){
    vector<vector<int>>ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    bool flag = true; // initially showing Left->Right

    while(!q.empty()){
        int size = q.size();
        vector<int>level;

        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            int index = flag? i : size-i+1;
            levl[index] = temp->data;

            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        flag = !flag;
        ans.push_back(level);
    }
    return ans;
}
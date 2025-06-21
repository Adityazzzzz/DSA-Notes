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

bool getPath(Node* root, vector<int>&arr, int k){
    if(!root) return false;

    arr.push_back(root->val);
    if(root->val == k) return true;
    if(getPath(root->left,arr,k) || getPath(root->right,arr,k)) return true;

    arr.pop_back();
    return false;
}
vector<int>solution(Node* A, int B){
    vector<int>arr;
    if(A==NULL) return arr;
    getPath(A, arr, B);
    return arr;
}
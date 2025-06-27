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

bool isValid(Node* root){
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}
bool isValidBST(Node* root, long long minval, long long maxval){
    if(!root) return true;
    if(root->val >=maxval || root->val <= minval) return false;
    
    return isValidBST(root->left,minval,root->val) && isValidBST(root->right,root->val,maxval)
}
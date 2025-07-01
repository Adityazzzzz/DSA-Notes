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

int maxNode, minNode, maxSize;

NodeValue(int minNode, int maxNode, int maxSize){
    this->maxNode = maxNode;
    this->minNode = minNode;
    this->maxSize = maxSize;
}

NodeValue largestBSThelper(TreeNode* root){
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

    auto left = largestBST(root->left);
    auto right = largestBST(root->right);

    if(left->maxNode < root->val  &&  root->val < right->minNode){
        return NodeValue(min(root->val, left->minNode), max(root->val, right->maxNode), left->maxSize + right->maxSize + 1);
    }

    return NodeValue(INT_MIN, INT_MAX, max(left->maxSize, right->maxSize));
}

int largestBST(TreeNode* root){
   return largestBSThelper(root).maxSize;
}
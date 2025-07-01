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


// only 2 node are misplaced - we have to swap them

TreeNode* first;
TreeNode* prev;
TreeNode* middle;
TreeNode* last;

void inorder(TreeNode* root){
    if(root==NULL) return;
    inorder(root->left);
    if(prev!=NULL && (root->val < prev->val)){
        if(first==NULL){
            first=prev;
            middle=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    inorder(root->right);
}

void recoverTree(TreeNode* root){
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if(first && last) swap(first->val,last->val);
    else if(first && middle) swap(first->val,middle->val);
}
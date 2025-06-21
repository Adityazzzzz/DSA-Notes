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


void changeTree(TreeNode* root) {
        if (root == NULL) return;
        int childsum = 0;
        if (root->left) childsum += root->left->val;
        if (root->right) childsum += root->right->val;

        if (childsum >= root->val) {
            root->val = childsum;
        } 
        else {
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }
        changeTree(root->left);
        changeTree(root->right);

        int finalsum = 0;
        if (root->left) finalsum += root->left->val;
        if (root->right)  finalsum += root->right->val;

        if (root->left || root->right) root->val = finalsum;
}
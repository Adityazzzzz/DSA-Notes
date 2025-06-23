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


TreeNode* prev = NULL;
void flatten(TreeNode* root) {
    if(root==NULL) return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;

    prev = root;
}


TreeNode* prev = NULL;
void flatten(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> st;
    st.push(root);  
    while (!st.empty()) {  
        TreeNode* cur = st.top(); 
        st.pop();  
        if (cur->right != NULL) st.push(cur->right); 
        if (cur->left != NULL)  st.push(cur->left); 
        if (!st.empty()) cur->right = st.top();  
        cur->left = NULL;  
    }
}



void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* pre = curr->left;
            while (pre->right) {
                pre = pre->right;
            }
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

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

class BSTiterator{
 private:
    stack<TreeNode*> stk;

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            stk.push(node);
            node = node->left;
        }
    }
 public:
    BSTiterator(TreeNode* root){
        pushAll(root);
    }
    bool hasNext(){
        return !stk.empty();
    }
    int next(){
        TreeNode* node = stk.top();
        stk.pop();
        pushAll(node->right);
        return node->val;
    }
     
};
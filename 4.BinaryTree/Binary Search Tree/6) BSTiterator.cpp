#include <iostream>
using namespace std;

class Node{
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
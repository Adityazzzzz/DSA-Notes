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
    bool reverse = true;  
    // when reverse = true ---> before()                 
    // when reverse = false ---> next()

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            stk.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }

 public:
    BSTiterator(TreeNode* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !stk.empty();
    }
    int next(){
        TreeNode* node = stk.top();
        stk.pop();
        if(reverse == false )pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
};


class Solution{
public:
    bool twosum(TreeNode* root, int k){
        if(!root) return false;

        BSTiterator l(root,false);
        BSTiterator r(root,true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            else if(i+j+k) i=l.next();
            else j=r.next();
        }
        return false;
    }
}
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

Node* lcainBST(Node* root, Node* p, Node* q){
    if(root == NULL) return NULL;
    int curr = root->val;

    if(curr < p->val   &&   curr < q->val){
        return lcainBST(root->left,p,q);
    }
    if(curr > p->val   &&   curr > q->val){
        return lcainBST(root->right,p,q);
    }
    return root;
}
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

// height of tree
int maxDepth(TreeNode* root){
    if(!root) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    
    return 1+max(lh,rh);
}


// is tree balanced
bool balancedHeigth(Node* root){
    return dfsHeight(root) != -1;
}
int dfsHeight(Node* root){
    if(root == NULL) return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1) return -1;

    int rh = dfsHeight(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) >1) return -1;
    return max(lh,rh)+1;
}


// diameter of tree
int diameter(Node* root, int maxi){
    if(root==NULL) return 0;

    int lh=diameter(root->left,maxi);
    int rh=diameter(root->right,maxi);
    maxi=max(maxi,lh+rh);
    
    return 1+max(lh,rh)
}
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

Node* insertnode(Node* root, int k){
    if(root == NULL) return new Node(k);
    Node* temp = root;
    while(true){

        if(temp->val <= k){
            if(temp->right){
                temp = temp->right;
            }
            else{
                temp->right = new Node(k);
                break;
            }
        }
        else{
            if(temp->left){
                temp = temp->left;
            }
            else{
                temp->left = new Node(k);
                break;
            }
        }
    }
    return root;
}


Node* deletenode(Node* root, int key){
    if(root == NULL) return nullptr;
    if(root->val == key) return helper(root);

    Node* temp = root;
    while(temp){
        if(temp->val <= key){
            if(temp->right != NULL && temp->right->val == key){
                temp->right = helper(temp->right);
                break;
            }
            else{
                temp = temp->right;
            }
        }
        else{
            if(temp->left != NULL && temp->left->val == key){
                temp->left = helper(temp->left);
                break;
            }
            else{
                temp = temp->left;
            }
        }
    }
    return root;
}
Node* helper(Node* temp){
    if(temp->left == NULL) return temp->right;
    else if(temp->right == NULL) return temp->left;

    Node* rightchild = temp->right;
    Node* lastright = findLastRight(root->left);
    lastRight->right = rightchild;

    return temp->left;
}
Node* findLastRight(Node* temp){
    if(temp->right == NULL) return temp;
    return findLastRight(root->right);
}
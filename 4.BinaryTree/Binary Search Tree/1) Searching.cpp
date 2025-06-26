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

Node* searching(Node* root, int k){
    Node* temp = root;
    while(temp != NULL  &&   temp->val != k){
        temp = (temp->val<k) ? temp->left : temp->right;
    }
    return temp;
}

// ceil value searching in BST
int findCeil(TreeNode* temp, int key){
    int ceil = -1; 
    while(temp){
        if(temp->val == key){
            ceil = temp->val;
            return ceil;
        } 

        if(key > temp->val) temp = temp->right;
        else{ 
            ceil = temp->val;
            temp = temp->left;
        }
    }
    return ceil;
}


// floor value
int findfloor(TreeNode* temp, int key){
    int floor = -1; 
    while(temp){
        if(temp->val == key){
            floor = temp->val;
            return floor;
        } 

        if(key < temp->val) temp = temp->left;
        else{ 
            floor = temp->val;
            temp = temp->right;
        }
    }
    return floor;
}
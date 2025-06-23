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

// morris - inorder
vector<int>morrisInorder(Node* root){
    vector<int>iot;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            iot.push_back(curr->val);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            } 
            if(prev->right == NULL){
                prev->right = curr; //making thread if not exist already
                curr = curr->left;
            }
            else{
                prev->right = nullptr;
                iot.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return iot;
}


// morris - preorder
vector<int>morrisPreorder(Node* root){
    vector<int>preot;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            preot.push_back(curr->val);
            curr = curr->right;
        }
        else{

            Node* prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }
        
            if(prev->right == NULL){
                prev->right = curr; //making thread if not exist already
                preot.push_back(curr->val);
                curr = curr->left;
            }
            else{
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return preot;
}
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

    Node(int val, Node* left1, Node* right1){
        data = val;
        left = left1;
        right = right1;
    }
};

void changeTree(Node* root){
    if(root == nullptr) return;

    int childSum = 0;
    if(root->left) childSum += root->left->data;
    if(root->right) childSum += root->right->data;

    if(childSum >= root->data){
        root->data = childSum;
    } 
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;

    if(root->left || root->right) root->data = total;
}

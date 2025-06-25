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
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

Node* lca(Node* root, Node* p, Node* q){
    Node* temp = root;
    if(temp == NULL || p == temp || q==temp) return temp;

    Node* left = lca(temp->left, p ,q);
    Node* right = lca(temp->right, p ,q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return temp;
}
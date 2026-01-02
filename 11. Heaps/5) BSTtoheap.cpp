#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// inorder: stores nodes in sorted order from BST
void inorderTraversal(Node* root, vector<int> &io) {
    if (!root) return;
    inorderTraversal(root->left, io);
    io.push_back(root->data);
    inorderTraversal(root->right, io);
}

// preorder: fill nodes from inorder array to make Min Heap
void preorderFill(Node* root, vector<int> &io, int &idx) {
    if (!root) return;

    root->data = io[idx++];   // smallest available value at root

    preorderFill(root->left, io, idx);
    preorderFill(root->right, io, idx);
}

// main conversion function
void convertBSTtoMinHeap(Node* root) {
    vector<int> io;
    inorderTraversal(root, io);   // get sorted values

    int idx = 0;
    preorderFill(root, io, idx);  // overwrite as min heap
}

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



void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
    if (!node || counter >= k) return;
    
    reverseInorder(node->right, counter, k, kLargest);
    counter++;
    if (counter == k) {
        kLargest = node->val;
        return;
    }
    reverseInorder(node->left, counter, k, kLargest);
}

void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
    if (!node || counter >= k) return;

    inorder(node->left, counter, k, kSmallest);
    counter++;
    if (counter == k) {
        kSmallest = node->val;
        return;
    }
    inorder(node->right, counter, k, kSmallest);
}

pair<int, int> findKth(TreeNode* root, int k) {
    int kSmallest = INT_MIN;
    int kLargest = INT_MIN;

    int counter = 0; 
    inorder(root, counter, k, kSmallest);

    int counter2 = 0; 
    reverseInorder(root, counter2, k, kLargest);

    return make_pair(kSmallest, kLargest);
}






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

// Q-1
int maxPathSum(Node* root){
    int maxi = INT_MIN;
    maxsum(root,maxi);
    return maxi;
}
int maxsum(Node* temp,int maxi){
    if(temp == NULL) return temp;

    int l = maxsum(temp->left,maxi);
    int ls = max(0,l);
    int r = maxsum(temp->right,maxi);
    int rs = max(0,r);

    maxi = max(maxi, (ls + rs + temp->data));

    return max(ls,rs)+temp->data
}


// Q-2
bool isIdenticalTree(Node* t1,Node* l2){
    if(t1==NULL || t2==NULL) return t1==t2;

    // return (t1->data == t2->data) && (t1->left == t2->left) && (t1->right == t2->right);
    return (t1->data == t2->data) && isIdenticalTree(t1->left, t2->left) && isIdenticalTree(t1->right, t2->right);
}
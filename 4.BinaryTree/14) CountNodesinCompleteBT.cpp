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

int countnodes(Node* root){
    if(root == NULL) return 0 ;

    int lh = findheightLEFT(root);
    int rh = findheightRIGHT(root);
    if(lh==rh) return (1<<lh)-1; // 2^lh-1

    return 1 + countnodes(root->left) + countnodes(root->right);
}

int findheightLEFT(Node* temp){
    int cnt=0;
    while(temp){
        cnt++;
        temp = temp->left;
    }
    return cnt;
}
int findheightRIGHT(Node* temp){
    int cnt=0;
    while(temp){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
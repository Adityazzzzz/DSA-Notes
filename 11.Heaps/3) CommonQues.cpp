#include <iostream>
using namespace std;


// kth smallest element
int kthSmallest(int arr[],int l,int r,int k){
    priority_queue<int> pq;

    for (int i=0;i<k;i++) {
        pq.push(arr[i]);
    }
    for (int i = k; i <= r; i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}
//--------------------------------------------------------------------------------------------------

// Is binary tree heap?
int countNodes(struct Node* root) {
    if (root == NULL)return 0;
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(struct Node* root, int index, int cnt) {
    if (root == NULL)
        return true;

    if (index >= cnt)
        return false;
    else {
        bool left  = isCBT(root->left,  2 * index + 1, cnt);
        bool right = isCBT(root->right, 2 * index + 2, cnt);
        return (left && right);
    }
}

bool isMaxOrder(struct Node* root) {
    if (root->left == NULL && root->right == NULL)  return true;

    if (root->right == NULL) {
        return (root->data > root->left->data);
    } 
    else{
        bool left  = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
    }
}

bool isHeap(struct Node* root) {
    int index = 0;
    int totalCount = countNodes(root);
    if (isCBT(root, index, totalCount) && isMaxOrder(root)) return true;
    else return false;
}
//---------------------------------------------------------------------------------------------------

// min cost of n ropes

long long minCost(long long arr[], long long n) {
    // create a min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    long long cost = 0;
    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

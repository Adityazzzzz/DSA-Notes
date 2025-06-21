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

int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int mini = q.front().second;
            int first, last;

            for (int i = 0; i < size; i++) {
                int it = q.front().second - mini;
                TreeNode* temp = q.front().first;
                q.pop();

                if (i == 0) first = it;
                if (i == size - 1) last = it;

                if (temp->left) q.push({temp->left, it * 2 + 1});
                if (temp->right) q.push({temp->right, it * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
}
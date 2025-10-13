#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int data,Node* left1,Node* right1){
        data=data1;
        left=left1;
        right=right1;
    }
};


string serialize(Node* root) {
    if (!root) return "";
    string s = "";
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) s = s + "#,";
        else {
            s = s + to_string(temp->val) + ",";
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return s;
}

Node* deserialize(string data) {
    if (data.empty())  return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');
    Node* newnode = new Node(stoi(str));

    queue<Node*> q;
    q.push(newnode);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str != "#") {
            Node* leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if (str != "#") {
            Node* rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return newnode;
}

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


// DFS - inorder,preorder,postorder (recursion)
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;

    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}


// BFS - for this we have to use (queue data structure)
vector<vector<int>> bfs(Node* root){

    vector<vector<int>>ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){

        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;

}


//---------------------------------------------------------------------------------------------------
//Iterative codes for DFS

vector<int>preorder(Node* root){
    vector<int>pot;
    if(root* == NULL) return pot;

    stack<Node*>st;
    st.push(root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        pot.push_back(temp->val);
        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
    }
    return pot;
}

vector<int>inorder(Node* root){
    vector<int>iot;
    stack<Node*>st;
    Node* temp = root;

    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()==true) break;

            temp = st.top();
            st.pop();
            iot.push_back(temp->val);
            temp = temp->right
        }
    }
    return pot;
}
//using 2 stack
vector<int> postOrder(Node* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;

    stack<Node*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(root->left != NULL) st1.push(root->left);
        if(root->right != NULL) st1.push(root->right);
    }
        
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}


// All traversals at same time 
vector<int>Traversals (Node* root){
    stack<pair<Node*,int>>st;
    
    st.push({root,1});
    if(root == NULL) return;

    vector<int>pre;
    vector<int>in;
    vector<int>post; 

    while(st.empty() == false){
        auto it=st.top();
        st.pop();

        //for preorder
        if(it.second == 1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left != NULL)  st.push(it.first->left, 1);
        }

        else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right != NULL)  st.push(it.first->right, 1);
        }

        else{
            post.push_back(it.first->val);
        }

    }
}

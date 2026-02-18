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

// bfs
vector<vector<int>> bfs(Node* root){
    if(!root) return {};

    vector<vector<int>>ans;;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int>list(size);
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();

            // list.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
            list.push_back(node->val);
        }
        ans.push_back(list);
    }
    return ans;
 
}
//---------------------------------------------------------------------------------
int maxDepth(TreeNode* root){
    if(!root) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    
    return 1+max(lh,rh);
}
//---------------------------------------------------------------------------------
int dfs(Node* root){
    if(!root) return 0;
    int lh=dfs(root->left);
    int rh=dfs(root->right);

    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh); 
}
bool balancedHeigth(Node* root){
    return (dfs(root)!=-1) return true;
}
//---------------------------------------------------------------------------------
//diameter
int dfs(TreeNode* root,int &maxi){
    if(!root) return 0;
    int lh=dfs(root->left,maxi);
    int rh=dfs(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root){
    int maxi=0;
    dfs(root,maxi);
    return maxi;
}

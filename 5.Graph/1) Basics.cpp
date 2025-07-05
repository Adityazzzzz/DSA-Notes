#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int adj[n+1][n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    return 0;
}

int main2(){
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        // if graph is undirected
        adj[x].push_back(y);
        // adj[y].push_back(x); 
    }
    return 0;
    
}


// BFS Traversal
vector<int>bfsgraph(int V, vector<int>& adj[]){
    vector<int>ans;

    int vis[V] = {0};
    vis[0] = 1;

    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for(auto it: adj[temp]){
            if( !vis[it] ){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}



// DFS Traversal
vector<int>dfsgraph(int V, vector<int>& adj[]){
    vector<int>list;
    int vis[n] = {0};
    int start = 0;

    dfs(start,adj,vis,list);
    return list;
}
void dfs(int node, vector<int>& adj[], int vis[], vector<int>& list){
    vis[node] = 1;
    list.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]) dfs(node,adj,vis,list);
    }
}
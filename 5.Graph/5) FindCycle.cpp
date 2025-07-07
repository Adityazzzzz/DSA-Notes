#include <iostream>
using namespace std;

// BFS Method
// O(N+2E)
// O(N)
bool detect(int src, vector<int>adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int,int>>q;
    q.push({src,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it,node})
            }
            else if(parent!=it) return true;
        }
    }
    return false;
}
bool findcycle(int V, vector<int>adj[]){
    int vis[] = {0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)) return true;
        }
    }
    return false;
}


// DFS Method

bool dfs(int node,int parent, vector<int>adj[], int vis[]){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node,adj,vis)==true) return true;
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
}
bool findcycle(int V, vector<int>adj[]){
    int vis[] = {0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,adj,vis)) return true;
        }
    }
    return false;
}





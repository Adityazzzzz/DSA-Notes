#include<iostream>
using namespace std;

// DFS
void dfs(int node,int vis[],stack<int>&st,vector<int>adj[]){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]) dfs(it,vis,st,adj);
    }
    st.push(node);
}
vecor<int>toposort(int V,vector<int>adj[]){
    int vis[V] = {0};
    stack<int>st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        } 
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}



// BFS : Kahn's Algorithm
vecor<int>toposort(int V,vector<int>adj[]){
    int degree[V]={0};
    for(int i=0;i<V;i++){
        for(auto it: adj[i]) degree[it]++;
    }

    queue<int>q;
    for(int i=0;i<V;i++){
        if(degree[i] == 0) q.push(i);
    }

    vector<int>ans;
    while(!q.empty()){
        int node = q.node();
        q.pop();
        ans.push_back(node);

        for(auto it:adj[node]){
            degree--;
            if(degree[it]==0) q.push.push(it);
        }
    }
    return ans;
}
#include <bits/stdc++.h>
using namespace std;

int timer = 0;
void dfs(int node,int parent,vector<int> &vis,vector<int> &time,vector<int> &low,vector<int> &mark,vector<int> adj[],int &timer){
    vis[node] = 1;
    time[node] = low[node] = timer;
    timer++
    int children = 0;

    for(int it:adj[node]){
        if(it == parent) continue; 
        if(!vis[it]){
            dfs(it,node,vis,time,low,mark,adj,timer);
            low[node] = min(low[node],low[it]);

            if(low[it] >= time[node] && parent != -1){
                mark[node] = 1; // articulation point
            }
            children++;
        }
        else{
            low[node] = min(low[node],time[it]);
        }
    }
    if(parent == -1 && children > 1){
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int n,vector<int> adj[]){
    vector<int> vis(n,0),time(n,-1),low(n,-1),mark(n,0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,time,low,mark,adj,timer);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(mark[i] == 1) ans.push_back(i);
    }

    if(ans.empty()) return{-1};
    return ans;
}



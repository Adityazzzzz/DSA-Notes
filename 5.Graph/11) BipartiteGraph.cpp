#include <bits/stdc++.h>
using namespace std;

bool dfs(int node,int nodecolor,int color[],vector<int>&adj[]){
    color[node] = col;
    for(auto it:adj[node]){
        if(color[it] == -1) dfs(it,!nodecolor,color,adj);
        else if(color[it] == nodecolor) return false;
    }

    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    int color[V] = {-1};

    for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(dfs(i,0,color,adj) == false) return false;
        } 
    }
    return true;
}
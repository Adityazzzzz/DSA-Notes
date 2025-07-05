#include <iostream>
using namespace std;

void dfs(int node, vector<int>adjls[], int vis[]){
    vis[node] = 1;
    for(auto it:adjls[node]){
        if(!vis[node]) dfs(it,adjls,vis)
    }
}

int numofprovinces(vector<vector<int>>adjmat, int V){
    // we have given adj matrix
    // so we convert matrix into list
    vector<int>adjls[V];
    for(int i=0;i<V;i++){
        for(int j=0;i<V;j++){
            if(adjmat[i][j] == 1  &&   i != j){
                adjls(i).push_back(j);
                adjls(j).push_back(i);
            }
        }
    }

    int vis[V]={0};
    int cnt = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjls,vis);
        }
    } 
    return ans;
}

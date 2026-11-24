#include<iostream>
using namespace std;

int dfs(int node,int parent){
    dp[node] = 1;
    for(int it:adj[node]){
        if(it==parent) continue;
        dp[node] += dfs(it,node);
    }
    return dp[node];
}
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark, vector<int> adj[], int &timer) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    int children = 0;

    for (int v : adj[u]) {
        if (v == p) continue; 
        if (!vis[v]) {
            dfs(v, u, vis, tin, low, mark, adj, timer);
            low[u] = min(low[u], low[v]);

            if (low[v] >= tin[u] && p != -1) {
                mark[u] = 1; // articulation point
            }
            children++;
        } 
        else{
            low[u] = min(low[u], tin[v]);
        }
    }
    if (p == -1 && children > 1) {
        mark[u] = 1;
    }
}

vector<int> articulationPoints(int n, vector<int> adj[]) {
    vector<int> vis(n, 0), tin(n, -1), low(n, -1), mark(n, 0);
    int timer = 0;

    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            dfs(i,-1,vis,tin,low,mark,adj,timer);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(mark[i] == 1) ans.push_back(i);
    }

    if (ans.empty()) return {-1};
    return ans;
}



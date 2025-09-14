#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<int> adjT[]) {
    vis[node] = 1;
    for (auto it : adjT[node]) {
        if (!vis[it]) {
            revDfs(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
        
    vector<int> adjT[V];
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    int sccCount = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            sccCount++;
            revDfs(node, vis, adjT);
        }
    }
    return sccCount;
}
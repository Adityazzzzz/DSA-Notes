#include <iostream>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[n+1];
    for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    // priority queue
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int>dist(n+1, 1e9);
    vector<int>parent(n+1);

    for(int i = 1; i <= n; i++) parent[i] = i;
    dist[1] = 0;
    q.push({0, 1}); // dist,node

    while(!q.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        q.pop();

        for(auto it2 : adj[node]) {
            int nextnode = it2.first;
            int edgeweight = it2.second;

            if(dis + edgeweight < dist[nextnode]){
                dist[nextnode] = dis + edgeweight;
                q.push({dist[nextnode], nextnode});
                parent[nextnode] = node;
            }
        }
    }


    if(dist[n] == 1e9) return {-1};
    vector<int> path;

    int node = n;
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;
}

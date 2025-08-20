#include <iostream>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;

    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(vis[node] == 1) continue;
        // add it to the mst
        vis[node] = 1;
        sum += wt;

        for(auto it: adj[node]) {
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode]) pq.push({edW, adjNode});
        }
    }
    return sum;
}

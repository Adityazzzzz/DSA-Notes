#include <iostream>
using namespace std;

class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(node == parent[node]) return node;
        // return findParent(parent[node]);
        return parent[node] = findUParent(parent[node]); // path compression
    }

    void unionByRank(int u,int v){
        int Pu = findUParent(u);
        int Pv = findUParent(v);
        if(Pu==Pv) return;

        if(rank[Pu]<rank[Pv]) parent[Pu] = Pv;
        else if(rank[Pu]>rank[Pv]) parent[Pv] = Pu;
        else{// Pu=Pv
            parent[Pv] = Pu;
            rank[Pu]++;
        }
    }

}

int kruskals(int V,vector<vector<int>>adj[]){
    // 1->2 & 2->1 : bidirectional
    vector<pair<int,pair<int,int>>>> edges;
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    int ans = 0;

    for(auto it:edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findParent(u) != ds.findUParent(v)){
            ans += wt;
            ds.unionByRank(u,v);
        }
    }
    return ans;
}

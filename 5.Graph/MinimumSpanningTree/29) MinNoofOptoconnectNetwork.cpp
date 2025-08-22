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

int Solve(int n, vector<vector<int>>& edge) {
    DisjointSet ds(n);
    int cntExtras = 0;
    for (auto it : edge) {
        int u = it[0];
        int v = it[1];
        if (ds.findUParent(u) == ds.findUParent(v)) {
            cntExtras++;
        }
        else {
            ds.unionByRank(u, v);
        }
    }

    int cntC = 0;
    for (int i = 0; i < n; i++) {
        if (ds.parent[i] == i) cntC++;
    }

    int ans = cntC - 1;
    if (cntExtras >= ans) return ans;
    return -1;
}

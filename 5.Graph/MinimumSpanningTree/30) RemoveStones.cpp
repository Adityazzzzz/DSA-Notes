#include <iostream>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
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

    void unionBySize(int u,int v){
        int Pu = findUParent(u);
        int Pv = findUParent(v);
        if(Pu==Pv) return;

        if(size[Pu] < size[Pv]){
            parent[Pu] = Pv;
            size[Pv] += size[Pu];
        }
        else{
            parent[Pv] = Pu;
            size[Pu] += size[Pv];
        }
    }

}

int maxRemove(vector<vector<int>>& stones, int n) {
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjointSet ds(maxRow + maxCol + 1);

    unordered_map<int, int> mpp;

    for (auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        mpp[nodeRow] = 1;
        mpp[nodeCol] = 1;
    }

    int cnt = 0;
    for (auto it : mpp) {
        if (ds.findPar(it.first) == it.first) {
            cnt++;
        }
    }
    return n-cnt;
}

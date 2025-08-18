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
        return parent[node] = findUParent(parent[node]);// path compression
    }

    void unionByRank(int u,int v){
        int Pu = findUParent(u);
        int Pv = findUParent(v);
        if(Pu==Pv) return;

        if(rank[Pu]<rank[Pv]) parent[Pu] = Pv;
        else if(rank[Pu]>rank[Pv]) parent[Pv] = Pu;
        else{
            parent[Pv] = Pu;
            rank[Pu]++;
        }
    }

}
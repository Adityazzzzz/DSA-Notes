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



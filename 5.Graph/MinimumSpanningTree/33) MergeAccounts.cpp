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

vector<vector<string>> mergeDetails(vector<vector<string>> &details) {
    int n = details.size();
    unordered_map<string, int> mapMailNode;
    DisjointSet(n);

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < details[i].size(); j++) {
            string mail = details[i][j];
            if(mapMailNode.find(mail) == mapMailNode.end()) {
                mapMailNode[mail] = i;
            } else {
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }

    vector<string> mergedMail[n];
    for(auto it : mapMailNode) {
        string mail = it.first;
        int node = ds.findPar(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for(int i = 0; i < n; i++) {
        if(mergedMail[i].size() == 0) continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(details[i]);
        for(auto it : mergedMail[i]) {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }

    return ans;
}

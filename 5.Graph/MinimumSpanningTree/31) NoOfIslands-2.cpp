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

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet ds(n * m);

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;

    vector<int> ans;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (auto it : operators) {
        int row = it[0];
        int col = it[1];
        if(vis[row][col] == 1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;

        int nodeNo = row * m + col;// imp

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
                
            if(nr >= 0 && nr < n   &&    nc >= 0 && nc < m    &&    vis[nr][nc] == 1){
                int adjNode = nr * m + nc;
                if(ds.findPar(nodeNo) != ds.findPar(adjNode)){
                    cnt--;
                    ds.unionBySize(nodeNo,adjNode);
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}
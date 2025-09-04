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

bool isValid(int nr, int nc, int n){
    return nr>=0 && nr<n && nc>=0 && nc<n;
}

int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n * n);
    
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            if (grid[row][col] == 0) continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            
            for (int ind = 0; ind < 4; ind++) {
                int nr = row + dr[ind];
                int nc = col + dc[ind];
                if (isValid(nr, nc, n)   &&   grid[nr][nc] == 1){

                    int nodeNo = row * n + col;
                    int adjNodeNo = nr * n + nc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    int mx = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 1) continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            
            set<int> components;
            for (int ind = 0; ind < 4; ind++) {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n)) {
                    if (grid[newr][newc] == 1) {
                        components.insert(ds.findUPar(newr * n + newc));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it : components) {
                sizeTotal += ds.size[it];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }

    for (int cellNo = 0; cellNo < n * n; cellNo++) {
        mx = max(mx, ds.size[ds.findUPar(cellNo)]);
    }
    return mx;
}

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUparent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionbyrank(int x, int y) {
        int px = findUparent(x);
        int py = findUparent(y);
        if (px == py) return;

        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[py] < rank[px]) parent[py] = px;
        else {
            parent[px] = py;
            rank[py]++; // ✅ fix
        }
    }
    void unionbysize(int x, int y) {
        int px = findUparent(x);
        int py = findUparent(y);
        if (px == py) return;

        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> mpp; // email -> account index

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                } else {
                    ds.unionbysize(i, mpp[mail]);
                }
            }
        }

        vector<vector<string>> merged(n);
        for (auto it : mpp) {
            string mail = it.first;
            int node = ds.findUparent(it.second);
            merged[node].push_back(mail);
        }

        // Step 3: Prepare result
        vector<vector<string>> result;
        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]); // account name
            temp.insert(temp.end(), merged[i].begin(), merged[i].end());
            
            result.push_back(temp);
        }

        return result;
    }
};

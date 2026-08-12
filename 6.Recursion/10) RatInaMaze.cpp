#include<iostream>
using namespace std;

void solve(int i,int j,vector<vector<int>>& m,int n,vector<string>& ans,string move,vector<vector<int>>& vis,int di[],int dj[]){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    vis[i][j] = 1;
    for(int ind=0;ind<4;ind++){
        int ni = i + di[ind];
        int nj = j + dj[ind];

        if(ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj] && m[ni][nj] == 1){
            solve(ni,nj,m,n,ans,move + dir[ind],vis,di,dj);
        }
    }
    vis[i][j] = 0;
}

vector<string> findPath(vector<vector<int>>& m,int n){

    vector<string> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));

    int di[] ={1,0,0,-1};  // D L R U
    int dj[] ={0,-1,1,0};

    if(m[0][0] == 1)
        solve(0,0,m,n,ans,"",vis,di,dj);

    return ans;
}
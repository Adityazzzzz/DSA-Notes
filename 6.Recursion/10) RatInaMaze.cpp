#include<iostream>
using namespace std;

void solve(int i,int j,vector<vector<int>>&m,int n,vector<string>&ans,string move,vector<vector<int>>&vis,int di[],int dj[]){

    if(i==n-1 && j==n-1){
        ans.push_back(move);
        return;
    }
    
    string dir = 'DLRU';
    for(int ind=0;ind<4;i++){
        int nexti = i + di[ind];
        int nextj = j + di[ind];
        if(nexti>=0 && nexti<n   &&   nextj>=0 && nextj<n    &&    !vis[nexti][nextj]  &&  m[nexti][nextj]==1){
            vis[i][j] = 1;
            solve(nexti,nextj,m,n,ans,move+dis[ind],vis,di,dj);
            vis[i][j] = 0;
        }
    }
}

vector<string>findPath(vector<vector<int>>&m,int n){
    vector<string>ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    int di[] = {1,0,0,-1}; // D,L,R,U
    int dj[] = {0,-1,1,0};

    if(m[0][0] == 1) solve(0,0,m,n,ans,"",vis,di,dj);
    return ans;
}
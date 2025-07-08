#include <iostream>
using namespace std;

void  dfs(int row,int col,vector<vector<char>>vis,vector<vector<char>>mat,int drow[],int dcol[]){
    vis[row][col]=1;
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0;i<4;i++){
        int nr = row + drow[i];
        int nc = col + dcol[i];

        if((nr>=0 && nr<n)  &&  (nc>=0 && nc<m)  &&  !vis[nr][nc]  &&  mat[nr][nc]=='O'){
            dfs(nr,nc,vis,mat,drow,dcol);
        }
    }
}

vector<vector<char>> fill(int n,int m, vector<vector<char>>mat){
    vector<vector<int>>vis(n,vector<int>(m,0));
    int drow[] ={-1,0,1,0};
    int dcol[] ={0,1,0,-1};
    
    // traverse boundary lines first
    for(int j=0;j<m;j++){
        if(!vis[0][j] && mat[0][j]=='O'){ // first row
            dfs(0,j,vis,mat,drow,dcol);
        }
        if(!vis[n-1][j] && mat[n-1][j]=='O'){ // last row
            dfs(n-1,j,vis,mat,drow,dcol);
        }
    }

    for(int i=0;i<n;i++){
        if(!vis[i][0] && mat[i][0]=='O'){ // first col
            dfs(i,0,vis,mat,drow,dcol);
        }
        if(!vis[i][m-1] && mat[i][m-1]=='O'){ // last col
            dfs(i,m-1,vis,mat,drow,dcol);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j]=='O'){
                mat[i][j] ='X';
            }
        }
    }
    return mat; 
}
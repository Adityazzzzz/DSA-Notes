#include <iostream>
using namespace std;

// using DFS

void dfs(int sr,int sc,vector<vector<int>>&image,int &initialcolor,int newcolor,int drow[],int dcol[]){
    ans[sr,sc] = newcolor;
    int n = image.size();
    int m = image[0].size();

    for(int i=0;i<4;i++){
        int nr = sr + drow[i];
        int nc = sc + dcol[i];
        if((nr>=0 && nr<n)  &&  (nc>=0 && nc<m)  && image[nr][nc]==initialcolor  &&  ans[nr][nc]!=newcolor){
            dfs(nr,nc,image,initialcolor,newcolor,drow,dcol);
        }
    }
}

vector<vector<int>>Floodfill(vector<vector<int>>&image,int sr,int sc, int newcolor){
    int initialcolor = image[sr][sc];
    vector<vector<int>>ans = image;
    int drow[] ={-1,0,1,0};
    int dcol[] ={0,1,0,-1};
    dfs(sr,sc,ans,initialcolor,newcolor,drow,dcol);
}
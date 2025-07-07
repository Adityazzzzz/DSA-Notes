#include <iostream>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }
    int drow[] ={-1,0,1,0};
    int dcol[] ={0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;
        for(int i=0;i<4;i++){
            int nr = now + drow[i];
            int nc = col + dcol[i];

            if((nr>=0 && nr<n)  &&  (nc>=0 && nc<m)  &&  (vis[nr][nc]==0) ){
                vis[nr][nc]=1;
                q.push({{nr,nc}, steps+1});
            }
        }
    }
    return dist;
}
#include <iostream>
using namespace std;

// using BFS

int rottenOranges(vector<vector<int>>grid){
    int n = grid.size();
    int m = grid[0].size();

    queue<pairpair<int,int>,int>>q;
    vector<vector<int>>vis;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                vis[i][j] = 2;
                q.push({{i,j},0})
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int time = 0;
    int drow = {-1,0,1,0};
    int dcol = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();
        
        time = max(time,t);
        for(int i=0;i<4;i++){
            int r = row + drow[i];
            int c = col + dcol[i];

            if((r>=0 && r<n)  &&  (c>=0 && c<m)  &&  (vis[r][c]!=2)  &&  (grid[r][c]==1)){
                vis[r][c]=1;
                q.push({{r,c}, t+1});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1  &&  vis[i][j] != 2){
               return -1;
            }
        }
    }

    return time;
}
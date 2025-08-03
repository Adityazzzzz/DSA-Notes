/* We are not using PQ because:
PQ is for always choosing minimum value
but here its a dist +1 always
same can be implemented using Queue

if the dist is non-uniform: then we take PQ
*/
#include <iostream>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {

    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        int dis = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m  && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]){
                dist[nr][nc] = 1 + dis;
                if (nr == destination.first && nc == destination.second) return dis + 1;
                q.push({1 + dis, {nr, nc}});
            }
        }
    }
    return -1;
}

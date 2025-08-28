#include<iostream>
using namespace std;

int f(int i, int j, vector<vector<int>>& triangle, int n) {
    if(i == n-1) {
        return triangle[n - 1][j];
    }
    if(dp[i][j] == -1) return dp[i][j];

    int down = triangle[i][j] + f(i+1,j,triangle,n);
    int diagonal = triangle[i][j] + f(i+1,j+1,triangle,n);

    return dp[i][j] =min(down, diagonal);
}
// ------------------------------------------------------------------------------------------------
// tabulation
int f(int i, int j, vector<vector<int>>& triangle, int n) {
    int dp[n][n] = {0};

    for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];

    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down,diagonal);
        }
    }
    return dp[0][0];
}
//-------------------------------------------------------------------------------------------------
// space optimization
int f(vector<vector<int>>& triangle, int n) {
    vector<int>front(n,0);

    for(int j=0;j<n;j++) front[j] = triangle[n-1][j];

    for(int i=n-2;i>=0;i--){
        vector<int>curr(n,0);
        for(int j=i;j>=0;j--){
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];

            curr[j] = min(down,diagonal);
        }
        front = curr;
    }
    return front[0];
}


//----------------------------------------------------------------------------------
// QUESTION: Min/Max in Path Sum , here we can move leftdiagonal,righrdiagonal and down
call functions by
maxi = max(maxi,f(n-1,j,matrix));

int f(int i, int j, vector<vector<int>> &matrix){
    if (j < 0 || j >= matrix[0].size()) return -1e8;
    if (i == 0) return matrix[0][j];
    if(dp[i][j] == -1) return dp[i][j];

    int u = matrix[i][j] + f(i - 1, j, matrix);
    int ld = matrix[i][j] + f(i - 1, j - 1, matrix);
    int rd = matrix[i][j] + f(i - 1, j + 1, matrix);

    return dp[i][j] = max(u, max(ld, rd));
}

//tabulation
int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = matrix[i][j] + dp[i-1][j];

            int ld = matrix[i][j];
            if(j-1>0) ld += dp[i-1][j-1];
            else ld += -1e9;

            int rd = matrix[i][j];
            if(j+1 < m) dp[i-1][j+1];
            else ld += -1e9;

            dp[i][j] = max(u,max(ld,rd));
        }
    }
    int maxi = 0;
    for(int j=0;j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>curr(m,0),prev(m,0);

    for(int j = 0; j < m; j++) prev[j] = matrix[0][j];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = matrix[i][j] + prev[j];

            int ld = matrix[i][j];
            if(j-1>0) ld += prev[j-1];
            else ld += -1e9;

            int rd = matrix[i][j];
            if(j+1 < m) prev[j+1];
            else ld += -1e9;

            curr[j] = max(u,max(ld,rd));
        }
        prev = curr;
    }
    int maxi = 0;
    for(int j=0;j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}


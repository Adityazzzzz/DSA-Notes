#include<iostream>
using namespace std;

int mod = 1e9 + 7;
int func(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
    if(i>=0 && j>=0 && mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    if(i<0 || j>0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = func(i-1,j,mat);
    int down = func(i,j-1,mat);
    
    return dp[i][j] = up+left % mod;
} 
//--------------------------------------------------------------------------------------------------
//tabulation
int func(int n,int m,vector<vector<int>>&mat){
    vector<vector<int>>dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1;
            else{
                int up=0,left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j] = up+left;
            }
        }
    }
    return dp[n-1][m-1];
}
//--------------------------------------------------------------------------------------------------
//space optimization
int func(int n,int m,vector<vector<int>>&mat){
    
    vector<int>prev(n);
    for(int i=0;i<n;i++){
        
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) curr[j] = 0;
            else if(i==0 && j==0) curr[j] = 1;
            else{
                int up=0,left=0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];

                curr[j] = up+left;
            }
        }
        prev = curr;
    }
    return prev[m-1];
}
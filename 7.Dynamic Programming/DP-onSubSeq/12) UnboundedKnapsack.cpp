#include<iostream>
using namespcae std

int f(int ind,int W,vector<int> &val,vector<int> &wt){
    if(ind == 0) return ((int)(W / wt[0])) * val[0];
    if(dp[ind][W]!=-1) return dp[ind][W];

    int notTake = 0 + f(ind-1,W,val,wt);
    int take = 0;
    if(wt[ind]<=W) take = val[ind] + f(ind,W-wt[ind],val,wt);
    
    return dp[ind][W] = max(take,notTake);
}
// -------------------------------------------------------------------------------------------
int unboundedknapsack(int n,int w,vector<int> &val,vector<int> &wt){
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i] = ((int)(i/wt[0])) * val[0];
    }

    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=w;tar++){
            int notTake = 0 + dp[ind-1][tar];
            int take = 0;
            if(wt[ind]<=w) take = val[ind] + dp[ind][tar-wt[ind]];

            dp[ind][tar] = max(take,notTake);
        }
    }
    return dp[n-1][w];
}

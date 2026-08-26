#include<iostream>
using namespcae std

int f(int ind,int k,vector<int> &nums){
    if(ind == 0){
        if(k % nums[0] == 0) return k/nums[0];
        return 1e9;
    }
    if(dp[ind][k] != -1) return dp[ind][k];

    int notTake = 0 + f(ind-1,k,nums);
    int take = INT_MAX;
    if(nums[ind]<=k) take = 1 + f(ind,k-nums[ind],nums);

    return dp[ind][k] = max(take,notTake);
}

// tabulation --------------------------------------------------------------------------------------
int minimumCoins(vector<int>& nums,int k){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));

    for(int i=0;i<=k;i++){
        if(i % nums[0] == 0) dp[0][i] = i/nums[0];
        else dp[0][i] = 1e9;
    }

    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=k;tar++){

            int notTake = dp[ind-1][tar];
            int take = INT_MAX; 
            if(nums[ind]<=tar) take = 1 + dp[ind][tar-nums[ind]];
            
            dp[ind][tar] = min(take,notTake);
        }
    }
    int ans = dp[n-1][k];
    if(ans >= 1e9) return -1;
    return ans;
}

// space optimization -----------------------------------------------------------------------------------
int minimumCoinsSpaceOptimized(vector<int>& nums,int k){
    int n = nums.size();
    vector<int>dp(k+1,1e9);
    dp[0] = 0;

    for(int i=0;i<n;++i){
        for(int j=nums[i];j<=k;++j){
            if(dp[j-nums[i]] != 1e9){
                dp[j] = min(dp[j],1 + dp[j-nums[i]]);
            }
        }
    }
    if(dp[k] >= 1e9) return -1;
    return dp[k];
}
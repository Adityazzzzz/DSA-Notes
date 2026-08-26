#include<iostream>
using namespcae std

int f(int ind,int T,vector<int> &nums){
    if(ind == 0){
        if(T % nums[0] == 0) return T/nums[0];
        return 1e9;
    }
    if(dp[ind][T] != -1) return dp[ind][T];

    int notTake = 0 + f(ind-1,T,nums);
    int take = INT_MAX;
    if(nums[ind]<=T) take = 1 + f(ind,T-nums[ind],nums);

    return dp[ind][T] = max(take,notTake);
}

// tabulation --------------------------------------------------------------------------------------
int minimumCoins(vector<int>& nums,int tar){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));

    for(int T=0;T<=tar;T++){
        if(T % nums[0] == 0) dp[0][T] = T/nums[0];
        else dp[0][T] = 1e9;
    }

    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=tar;T++){

            int notTake = dp[ind-1][T];
            int take = INT_MAX; 
            if(nums[ind]<=T) take = 1 + dp[ind][T-nums[ind]];
            
            dp[ind][T] = min(take,notTake);
        }
    }
    int ans = dp[n-1][tar];
    if(ans >= 1e9) return -1;
    return ans;
}

// space optimization -----------------------------------------------------------------------------------
int minimumCoinsSpaceOptimized(vector<int>& nums,int tar){
    int n = nums.size();
    vector<int>dp(tar+1,1e9);
    dp[0] = 0;

    for(int i=0; i<n;++i){
        for(int j = nums[i]; j<=tar; ++j){
            if(dp[j-nums[i]] != 1e9){
                dp[j] = min(dp[j],1 + dp[j-nums[i]]);
            }
        }
    }

    if(dp[tar] >= 1e9) return -1;
    return dp[tar];
}
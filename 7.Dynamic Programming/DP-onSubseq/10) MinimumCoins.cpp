#include<iostream>
using namespcae std

int f(int ind, int T, vector<int> &nums) {
    if(ind == 0){
        if (T % nums[0] == 0) return T / nums[0];
        return 1e9;
    }
    if(dp[ind][T] != -1) return dp[ind][T];

    int notTake = 0 + f(ind - 1, T, nums);
    int take = INT_MAX;
    if (nums[ind] <= T) take = 1 + f(ind, T - nums[ind], nums);

    return dp[ind][T] = max(take, notTake);
}
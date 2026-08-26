#include <bits/stdc++.h>
using namespace std;

int minDiffSubsetSum(vector<int>&arr,int target){
    int totSum = 0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }
    int k = totSum;

    // Subset sum --------------- 
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[0]<=k) dp[0][arr[0]] = true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake = dp[indd-1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[indd-1][targetd-arr[ind]];

            dp[ind][target] = take | notTake;
        }
    }
    // ---------------------------


    
    // now only check last row(half) of Table, which are true
    int mini = 1e9;
    for(int i=0;i<=totSum/2;i++){
        if(dp[n-1][i] == true){
            mini = min(mini,abs((totSum-i) - i));
        }
    }
    return mini;
}
#include<iostream>
using namespcae std

long long f(int ind,int k,int &arr){
    if(ind==0) return (k % arr[0] == 0);
    if(dp[ind][k]!=-1) return dp[ind][k];

    long long notTake = f(ind-1,k,arr);
    long long take = 0;
    if(a[ind]<=k) take = f(ind,k-arr[ind],arr);

    return dp[ind][k] = take + notTake;
}

// tabulation --------------------------------------------------------------------------------------
long long countWaysToMakeChange(int arr[],int n,int k){
    vector<vector<long long>> dp(n,vector<long long>(k+1,0));
    for(int i=0;i<=k;i++){
        dp[0][i] = (i % arr[0] == 0);
    }

    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=k;tar++){
            long long notTake = dp[ind-1][tar];
            long long take = 0;
            if(arr[ind]<=tar) take = dp[ind][tar-arr[ind]];

            dp[ind][tar] = take + notTake;
        }
    }
    return dp[n-1][k];
}

// space optimization -----------------------------------------------------------------------------------
long long countWaysToMakeChange(int arr[],int n,int k){
    vector<int>prev(k+1,0),curr(k+1,0)
    for(int i=0;i<=k;i++){
        prev[i] = (i % arr[0] == 0);
    }

    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=k;tar++){
            long long notTake = prev[tar];
            long long take = 0;
            if(arr[ind]<=tar) take = curr[tar-arr[ind]];

            curr[tar] = take + notTake;
        }
    }
    return prev[k];
}

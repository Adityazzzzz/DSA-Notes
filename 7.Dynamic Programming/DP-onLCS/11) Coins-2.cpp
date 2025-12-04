#include<iostream>
using namespcae std

long long f(int ind,int T,int &arr){
    if(ind == 0) {
        return (T % arr[0] == 0);
    }
    if(dp[ind][T] != -1) return dp[ind][T];

    long long notTake = f(ind-1,T,arr);
    long long take = 0;
    if(a[ind] <= T) take = f(ind,T-arr[ind],arr);

    return dp[ind][T] = take + notTake;
}


// tabulation --------------------------------------------------------------------------------------
long long countWaysToMakeChange(int denominations[], int n, int value){

    vector<vector<long long>> dp(n, vector<long long>(value + 1, 0));
    for(int T=0;T<=value;T++){
        dp[0][T] = (T%a[0] == 0);
    }

    for(int ind = 1; ind < n; ind++) {
        for(int T = 0; T <= value; T++) {
            long long notTake = dp[ind - 1][T];
            long long take = 0;
            if(a[ind] <= T) take = dp[ind][T - a[ind]];

            dp[ind][T] = take + notTake;
        }
    }

    return dp[n - 1][value];
}

// space optimization -----------------------------------------------------------------------------------
long long countWaysToMakeChange(int denominations[], int n, int value){

    vector<int>prev(value+1,0),curr(value+1,0)
    for(int T=0;T<=value;T++){
        prev[T] = (T%a[0] == 0);
    }

    for(int ind = 1; ind < n; ind++) {
        for(int T = 0; T <= value; T++) {
            long long notTake = prev[T];
            long long take = 0;
            if(a[ind] <= T) take = curr[T - a[ind]];
            
            curr[T] = take + notTake;
        }
        prev = curr;
    }

    return prev[value];
}

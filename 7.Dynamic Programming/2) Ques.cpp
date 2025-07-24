#include<iostream>
using namespace std;

// climbing stairs
int solve(int n,vector<int> &dp){
    if(n<=2) return n;
    if(dp[n]!=-1) return dp[n]; 
        
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}
int climbStairs(int n) {.
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}


int climbStairs(int n) {
    if (n <= 2) return n;

    int prev1 = 2;
    int prev2 = 1;
    int cur = 0;
    for (int i = 3; i < n; i++) {
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return cur;        
}
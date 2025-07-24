#include<iostream>
using namespace std;

// recursion method
int func(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!= -1) return dp[n];

    return dp[n] = func(n-1,dp) + func(n-2,dp);
}
void solve(int n){
    vector<int>dp(n+1,-1);
    func(n,dp)
}

// tabular method
void solve(int n){
    int prev = 1;
    int prev2 = 0;
    for(int i=2;i<=n;i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
}
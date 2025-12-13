#include<bits/stdc++.h>
using namespace std;

int func(int i,int j,vector<int>&arr){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int maxi = INT_MIN;
    for(int ind=i;ind<=j;ind++){
        int cost = (arr[i-1]*arr[ind]*arr[j+1]) + func(i,ind-1,arr) + func(ind+1,j,arr);
        maxi = max(maxi,cost);
    }
    return dp[i][j] = maxi;
}

int burstBalloons(int n,vector<int>&arr){
    // insert 1 at beginning and end
    arr.push_back(1);
    arr.insert(arr.begin(),1);
    vector<vector<int>>dp(n+1,vector<int>(n+1,0))

    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j) continue;
            int maxi = INT_MIN;
            for(int ind=i;ind<=j;ind++){
                int cost = (arr[i-1]*arr[ind]*arr[j+1]) + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi,cost);
            } 

            dp[i][j] = maxi;
        }
    }
    return dp[1][n];

}